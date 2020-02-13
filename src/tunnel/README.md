# Tunnel exploration module

This Crazyflie submodule enables a fleet of UAVs to explore tunnel-like environments while keeping a stable connection even after the first drone goes too far from the base station. It is part of a research project conducted at INRIA Nancy Grand-Est (France) by the research team LARSEN.

* Author : Pierre LACLAU (GitHub @MadeInPierre)

* Maintainer : LARSEN, INRIA

## General information

## Installation & flashing
### Cloning the repos

There are two separate firmwares that need to be flashed on each Crazyflie. Clone the two repos and checkout the _Tunnel_ project's branches:

```
git clone https://github.com/MadeInPierre/crazyflie-firmware.git 
git clone https://github.com/MadeInPierre/crazyflie2-nrf-firmware.git

cd crazyflie-firmware && git checkout cavemod && cd ..
cd crazyflie2-nrf-firmware && git checkout p2p_communication && cd ..
```

Follow the installation instructions on each of the repos' README files (located in the root folders). You should then be able to compile both repos:

```
# In crazyflie-firmware/
make all

# In crazyflie2-nrf-firmware/
make all BLE=0
```

Note that Bluetooth must be disabled in the nRF51 firmware in order to use the P2P Communication Protocol.

### Flashing the firmwares

Once both repos have been compiled, you can flash both firmwares with the following methods.

#### Flashing the STM32

Flashing the STM32 chip can be done through two methods:

2. Using the Crazyradio:
Flashing using the radio is supported but flashing fails can happen. Turn the Crazyflie on in Bootloader mode by holding the power button for 3 seconds, conenct the Crazyradio through USB and run:

```
# In crazyflie-firmware/
make cload
```

1. Using the STLink v2 debugger (**recommended**, `openocd` must be installed):
A faster and reliable way of flashing the main chip is to use a JTAG USB Debugger (Bitcraze officially supports the STLink v2). Simply power on the Crazyflie by pressing the power button, connect the debugger via USB and JTAG on both ends and run:
```
# In crazyflie-firmware/
make flash
```

#### Flashing the nRF51

Flashing the communication chip only works using the Crazyradio. Turn the Crazyflie on in Bootloader mode by holding the power button for 3 seconds, connect the Crazyradio through USB and run:

```
# In crazyflie2-nrf-firmware/
make cload BLE=0
```

### Changing the drones' addresses
Each Crazyflie ships by default with the address `E7E7E7E7E7`. However, this project requires that the drones have unique consecutive addresses from `E7E7E7E7E0` to `E7E7E7E7E(n-1)` where `n` is the number of drones in the exploration chain. 

In order to change a drone's address, firstly clone the python client repo containing many useful examples:

```
git clone https://github.com/bitcraze/crazyflie-lib-python.git
cd crazyflie-lib-python/examples
python3 write-eeprom.py
```

You should now have a ready-to-use Tunnel Exploration UAV.

## Project Structure
