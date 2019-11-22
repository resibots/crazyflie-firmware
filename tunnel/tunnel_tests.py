import cflib.crtp
from cflib.crazyflie import Crazyflie
from cflib.crazyflie.syncCrazyflie import SyncCrazyflie
from cflib.positioning.motion_commander import MotionCommander
from cflib.utils.multiranger import Multiranger
from cflib.crazyflie.log import LogConfig
from cflib.crtp.crtpstack import CRTPPacket, CRTPPort

import time, struct
from pynput.keyboard import Listener, Key, KeyCode
import logging
import time

import pandas as pd
from math import pi
import matplotlib.pyplot as plt

class bcolors:
    NONE = ''
    HEADER = '\033[95m'
    OKBLUE = '\033[94m'
    OKGREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'
    ENDC = '\033[0m'
    BOLD = '\033[1m'
    UNDERLINE = '\033[4m'

def color_print(color, text, newline=True):
    endl = '\n' if newline else ''
    print(color + text + bcolors.ENDC, end=endl)

# URI to the Crazyflie to connect to
uri = 'radio://0/80/2M/E7E7E7E7E'
color_print(bcolors.BOLD, "Target address = ", newline=False)
color_print(bcolors.NONE, "E7E7E7E7E", newline=False)
uri += input()

color_print(bcolors.BOLD, "Number of active drones (0 to skip): ", newline=False)
n_drones = int(input())
start_time = 0
counter = 0
prev_ping_time = 0

scans = []

# Custom CRTP tunnel port
RADIO_PORT_TUNNEL = 0x0A

# Custom CRTP tunnel channels
CRTP_TUNNEL_CHANNEL_PING      = 0x00
CRTP_TUNNEL_CHANNEL_PARAM     = 0x01
CRTP_TUNNEL_CHANNEL_COMMANDER = 0x02
CRTP_TUNNEL_CHANNEL_COMMAND   = 0x03

# Tunnel parameter selector
TUNNEL_PARAM_NDRONES = 0x00
TUNNEL_PARAM_MODE    = 0x01

# Drone mode
DRONE_MODE_MANUAL    = 0x00
DRONE_MODE_AUTO      = 0x01

# Tunnel commander options
TUNNEL_COMMANDER_MOVE = 0x00
TUNNEL_COMMANDER_GOTO = 0x01

# Tunnel command selector
CRTP_TUNNEL_COMMAND_TAKE_OFF       = 0x00 # Start flying and do our thing!
CRTP_TUNNEL_COMMAND_SET_BEHAVIOR   = 0x01 # Set a specific behavior while the drone is flying
CRTP_TUNNEL_COMMAND_SET_MODE       = 0x02 # Set this drone's mode (will not propagate to other drones)
CRTP_TUNNEL_COMMAND_RTH            = 0x03 # Return to home automatically
CRTP_TUNNEL_COMMAND_LAND           = 0x04 # Land no matter where we are (e.g. to manually save battery)
CRTP_TUNNEL_COMMAND_CUT_MOTORS     = 0x05 # Cut the motors and return to Idle state (for emergencies or tests)

# Tunnel behaviors
TUNNEL_BEHAVIOR_IDLE        = 0 # Stay on the ground, motors off
TUNNEL_BEHAVIOR_TAKE_OFF    = 1 # Take off slowly with a specified velocity
TUNNEL_BEHAVIOR_HOVER       = 2 # Stay still at the current position
TUNNEL_BEHAVIOR_GOTO        = 3 # Reach a specified tunnelDistance
TUNNEL_BEHAVIOR_POSITIONING = 4 # Stay between the leader and follower (RSSI based)
TUNNEL_BEHAVIOR_RECONNECT   = 5 # Notify all drones behind and hover until the leader comes back
TUNNEL_BEHAVIOR_ROLLBACK    = 6 # Notify all drones ahead and go back until the tunnel to reconnect
TUNNEL_BEHAVIOR_SCAN        = 7 # Turn 90 degrees and scan the room, then point to the tunnel
TUNNEL_BEHAVIOR_LAND        = 8 # Land slowly with a specified velocity

keystates = {
    "up"   : 0,
    "down" : 0,
    "left" : 0,
    "right": 0,

    "q": 0,
    "r": 0,
}

logging.basicConfig(level=logging.WARN)

'''
Sending messages
'''

class CRTPSender():
    def sendCRTPPacket(self, port, channel, data, droneid):
        pk = CRTPPacket()
        pk.set_header(RADIO_PORT_TUNNEL, channel)
        pk.data = struct.pack('<b', droneid) + data
        self.cf.send_packet(pk)
    
    def __init__(self, cf):
        self.cf = cf

class TunnelCommunicator(CRTPSender):
    def sendCRTPTunnelPacket(self, channel, data, droneid=None):
        self.sendCRTPPacket(RADIO_PORT_TUNNEL, channel, data, droneid if droneid is not None else self.current_id)
    
    def set_drone_id(self, droneid, verbose=True):
        if verbose:
            color_print(bcolors.OKGREEN, "Setting drone id to {}".format(droneid))
        self.current_id = droneid
    
    def reset_drone_id(self, verbose=True):
        if verbose:
            color_print(bcolors.OKGREEN, "Resetting drone id to {}".format(self.default_id))
        self.current_id = self.default_id

    '''
    Parameters
    '''
    def set_ndrones(self, n_drones, verbose=True):
        if verbose:
            color_print(bcolors.OKGREEN, "Setting NDrones to {}".format(n_drones))
        self.sendCRTPTunnelPacket(channel=CRTP_TUNNEL_CHANNEL_PARAM,
            data=struct.pack('<bb', TUNNEL_PARAM_NDRONES, n_drones))
    
    def set_mode(self, mode, broadcast=True, verbose=True):
        if verbose:
            color_print(bcolors.OKGREEN, "Setting {} mode".format("auto" if mode is DRONE_MODE_AUTO else "manual"))
        if broadcast: # set the mode param in the drone to broadcast to all drone
            self.sendCRTPTunnelPacket(channel=CRTP_TUNNEL_CHANNEL_PARAM,
                data=struct.pack('<bb', TUNNEL_PARAM_MODE, mode))
        else: # send a mode command to apply only to the specified drone
            self.sendCRTPTunnelPacket(channel=CRTP_TUNNEL_CHANNEL_COMMAND,
                data=struct.pack('<bb', CRTP_TUNNEL_COMMAND_SET_MODE, int(mode)))

    '''
    Commander
    '''
    def move(self, vx, vy, verbose=True):
        if verbose:
            color_print(bcolors.OKGREEN, "Moving drone by x={} y={}".format(vx, vy))
        self.sendCRTPTunnelPacket(channel=CRTP_TUNNEL_CHANNEL_COMMANDER,
            data=struct.pack('<bbb', 0x00, vx, vy))

    def goto(self, goal, verbose=True): # Goal in meters, 25.5 meters max
        if verbose:
            color_print(bcolors.OKGREEN, "Goto {:.2f}".format(goal))
        self.sendCRTPTunnelPacket(channel=CRTP_TUNNEL_CHANNEL_COMMANDER,
            data=struct.pack('<bb', 0x01, int(goal * 10)))

    '''
    Commands
    '''
    def takeoff(self, verbose=True):
        if verbose:
            color_print(bcolors.OKGREEN, "Taking off!")
        self.sendCRTPTunnelPacket(channel=CRTP_TUNNEL_CHANNEL_COMMAND,
            data=struct.pack('<b', CRTP_TUNNEL_COMMAND_TAKE_OFF))

    def set_behavior(self, behavior, verbose=True):
        if verbose:
            color_print(bcolors.OKGREEN, "Setting behavior to {}".format(behavior))
        self.sendCRTPTunnelPacket(channel=CRTP_TUNNEL_CHANNEL_COMMAND,
            data=struct.pack('<bb', CRTP_TUNNEL_COMMAND_SET_BEHAVIOR, behavior))
    
    def scan(self, verbose=True):
        if verbose:
            color_print(bcolors.OKGREEN, "Starting single scan")
        self.set_behavior(TUNNEL_BEHAVIOR_SCAN, verbose=False)

    def land(self, verbose=True):
        if verbose:
            color_print(bcolors.OKGREEN, "Landing!")
        self.sendCRTPTunnelPacket(channel=CRTP_TUNNEL_CHANNEL_COMMAND,
            data=struct.pack('<b', CRTP_TUNNEL_COMMAND_LAND))

    def rth(self, verbose=True):
        if verbose:
            color_print(bcolors.OKGREEN, "Returning to Home!")
        self.sendCRTPTunnelPacket(channel=CRTP_TUNNEL_CHANNEL_COMMAND,
            data=struct.pack('<b', CRTP_TUNNEL_COMMAND_RTH))

    def cut_motors(self, verbose=True):
        if verbose:
            color_print(bcolors.FAIL, "Cuttiing motors off!")
        self.sendCRTPTunnelPacket(channel=CRTP_TUNNEL_CHANNEL_COMMAND,
            data=struct.pack('<b', CRTP_TUNNEL_COMMAND_CUT_MOTORS))

    def __init__(self, cf, default_id):
        super().__init__(cf)
        self.default_id = default_id
        self.current_id = default_id

'''
Keyboard listener
'''
def _on_press(key):
    if key == KeyCode.from_char('w'):
        keystates["up"] = 1
    if key == KeyCode.from_char('s'):
        keystates["down"] = 1
    if key == KeyCode.from_char('a'):
        keystates["left"] = 1
    if key == KeyCode.from_char('d'):
        keystates["right"] = 1
    if key == KeyCode.from_char('q'):
        keystates["q"] = 1
    if key == KeyCode.from_char('r'):
        keystates["r"] = 1

def _on_release(key):
    if key == KeyCode.from_char('w'):
        keystates["up"] = 0
    if key == KeyCode.from_char('s'):
        keystates["down"] = 0
    if key == KeyCode.from_char('a'):
        keystates["left"] = 0
    if key == KeyCode.from_char('d'):
        keystates["right"] = 0

'''
Logging
'''
def log_msg(pk, data_int=False, color=bcolors.NONE):
    port_name = {
        0:  "CONSOLE",
        10: "TUNNEL ",
        15: "P2P    "
    }
    color_print(bcolors.BOLD, "[{} {}:{}] ".format(port_name[pk.port], str(pk.port), str(pk.channel)), newline=False)

    text = ''.join([(str(c) + " " if data_int is True else chr(c)) for c in pk.data])
    
    if data_int:
        text += '\n'

    if color is bcolors.NONE:
        if "STATUS" in text:
            color = bcolors.OKBLUE


    color_print(color, text, newline=False)

def on_ping(pk):
    global counter
    global prev_ping_time
    color_print(bcolors.HEADER, "Ping #{} ({:.0f}ms since last ping): {}ms at {:.2f}sec".format(counter, time.time()*1000 - prev_ping_time,
                                                                        int(pk.data[-1]), time.time() - start_time))
    counter += 1
    prev_ping_time = time.time()*1000
    pk.data = pk.data[:-1] # Remove ping time

    drone0statusStart = pk.data[:2]
    pk.data = pk.data[2:]

    N = 3
    infoList = [pk.data[n:n+N] for n in range(0, len(pk.data), N)] # group drone elements into sublists

    rssis_string  = "    "
    rssis_string += "[{}]".format(drone0statusStart.hex())
    rssis_string += ''.join(["--{}--[{}]".format(r[0], r[1:].hex()) for (i, r) in enumerate(infoList)])
    color_print(bcolors.HEADER, rssis_string)

'''
Message callbacks
'''
def on_console_msg(pk):
    log_msg(pk)
    pass

def on_tunnel_msg(pk):
    if pk.channel == 0:
        on_ping(pk)
    elif pk.channel == 1:
        color_print(bcolors.HEADER, "New scan arrived:")
        log_msg(pk, data_int=True, color=bcolors.HEADER)
        scans.append([int(v) for v in pk.data])
    else:
        log_msg(pk, data_int=True)

def on_p2p_msg(pk):
    log_msg(pk)

'''
Individual tests
'''
def test_simple_listen(tunnel, wait=300):
    time.sleep(wait)

def test_mode(tunnel, wait=3):
    tunnel.set_drone_id(0)
    tunnel.set_mode(DRONE_MODE_AUTO, broadcast=False)
    time.sleep(wait)

    tunnel.set_mode(DRONE_MODE_MANUAL, broadcast=False)
    time.sleep(3)


def test_quick_hover(tunnel, wait=5):
    tunnel.takeoff()
    time.sleep(2)
    tunnel.land()
    time.sleep(3)

def test_scan(tunnel, wait=5):
    tunnel.takeoff()
    time.sleep(2)

    tunnel.scan()
    time.sleep(12)

    tunnel.land()
    time.sleep(5)

def test_goto_steps(tunnel):
    DISTANCE = 3.0 # Distance to explore in the tunnel
    STEPDIST = 0.5 # Every which step to make a pause
    tunnel.takeoff()
    time.sleep(3)

    distance = 0.0
    for _ in range(int(DISTANCE / STEPDIST)):
        distance += STEPDIST
        tunnel.goto(distance)
        time.sleep(5)

    tunnel.land()
    time.sleep(5)

def test_goto(tunnel, dist=0.5):
    tunnel.takeoff()
    time.sleep(3)
    
    tunnel.goto(float(dist))
    time.sleep(float(dist) / 0.2)

    time.sleep(3)
    tunnel.land()
    time.sleep(5)

def test_goto_middlescan(tunnel, dist=3.5):
    tunnel.takeoff()
    time.sleep(3)
    
    # First half
    tunnel.goto(dist / 2.0)
    time.sleep(1 + (dist / 2.0) / 0.2)

    # Scan
    tunnel.scan()
    time.sleep(13)

    # Last half
    tunnel.goto(dist)
    time.sleep(1 + dist / 0.2)

    time.sleep(3)
    tunnel.land()
    time.sleep(5)

def test_move(tunnel):
    time_sleep = 1.0
    time_sim   = 300.0

    tunnel.takeoff()
    time.sleep(2)

    with Listener(on_press=_on_press, on_release=_on_release):
        for _ in range(int(time_sim / time_sleep)):
            # Stop the drone if Q is pressed
            if(keystates["q"] == 1):
                color_print(bcolors.WARNING, "Stopping drone!")
                tunnel.setCanFly(False)
                break

            # Set a desired velocity
            vel = (keystates["up"] - keystates["down"], keystates["left"] - keystates["right"])
            tunnel.move(vel[0], vel[1])
            time.sleep(time_sleep)

    tunnel.land()
    time.sleep(5)

def tool_set_manual(tunnel):
    tunnel.set_mode(DRONE_MODE_MANUAL, broadcast=False)
    time.sleep(2)

def tool_set_auto(tunnel):
    tunnel.set_mode(DRONE_MODE_MANUAL, broadcast=False)
    time.sleep(2)

def final_exploration(tunnel):
    rth = False

    # Set all drones to auto and launch the head drone
    tunnel.set_mode(DRONE_MODE_AUTO, broadcast=True)
    time.sleep(2)

    with Listener(on_press=_on_press, on_release=_on_release):
        while True:
            if keystates["q"] == 1:
                color_print(bcolors.WARNING, "Stopping exploration!")
                break
            if keystates["r"] == 1:
                tunnel.rth()
                rth = True

            if rth is False:
                # Set a desired velocity
                vel = (keystates["up"] - keystates["down"], keystates["left"] - keystates["right"])
                tunnel.set_drone_id(0, verbose=False)
                tunnel.move(vel[0], vel[1])
                tunnel.reset_drone_id(verbose=False)
            else:
                pass # TODO quit when rth done

            time.sleep(0.3)

    # Land all drones by ending the exploration
    tunnel.reset_drone_id(verbose=False)
    tunnel.set_mode(DRONE_MODE_MANUAL, broadcast=True)
    time.sleep(5)

tests = [
    # Unit tests
    ("test_simple_listen"  , test_simple_listen  ),
    ("test_mode"           , test_mode           ),
    ("test_quick_hover"    , test_quick_hover    ),
    ("test_scan"           , test_scan           ),
    ("test_move"           , test_move           ),
    ("test_goto"           , test_goto           ),
    ("test_goto_steps"     , test_goto_steps     ),
    ("test_goto_middlescan", test_goto_middlescan),

    # Tools and helpers
    ("tool_set_manual"     , tool_set_manual     ),
    ("tool_set_auto"       , tool_set_auto       ),

    # Real exploration algorithms
    ("final_exploration"   , final_exploration   ),
]

'''
Visualization
'''
def show_scans():
    for scan in scans:
        angles = [n / float(len(scan)) * 2 * pi for n in range(len(scan))]
        scan += scan[:1]
        angles += angles[:1]

        ax = plt.subplot(111, polar=True)

        #Add the attribute labels to our axes
        # plt.xticks(angles[:-1], Attributes)

        #Plot the line around the outside of the filled area, using the angles and scan calculated before
        ax.plot(angles, scan)

        #Fill in the area plotted in the last line
        ax.fill(angles, scan, 'teal', alpha=0.2)

        #Give the plot a title and show it
        ax.set_title("Scan")
        plt.show()


'''
Main args & function
'''
if __name__ == '__main__':
    color_print(bcolors.BOLD, "Choose which plan to run:")
    for (i, t) in enumerate(tests):
        color = bcolors.HEADER if "final" in tests[i][0] else bcolors.OKBLUE
        color = bcolors.HEADER if "tool"  in tests[i][0] else color
        color_print(color, "    - {}. {}".format(i, tests[i][0]))
    chosen_test = int(input("Index chosen:"))
    color_print(bcolors.OKGREEN, "Launching module '{}'!\n\n".format(tests[chosen_test][0]))

    # Connect to crazyflie
    cflib.crtp.init_drivers(enable_debug_driver=False)
    cf = Crazyflie(rw_cache='./cache')
    cf.open_link(uri)

    # Add packet callbacks
    cf.add_port_callback(RADIO_PORT_TUNNEL, on_tunnel_msg)
    cf.add_port_callback(CRTPPort.CONSOLE, on_console_msg)
    time.sleep(3)
    start_time = time.time()

    tunnel = TunnelCommunicator(cf, int(uri[-1], base=16))

    if n_drones > 0:
        tunnel.set_ndrones(n_drones)

    tests[chosen_test][1](tunnel)

    cf.close_link()

    if scans:
        show_scans()
