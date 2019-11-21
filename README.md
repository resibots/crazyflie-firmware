# Exploration in confined environments

This fork aims to build a coordination algorithm with Crazyflies for exploring constrained and underground environments (mines, tunnels, pipes...).

A human can pilot a Crazyflie equipped with a camera and distance sensors in all directions. An avoidance system keeps the drone away from obstacles. When the signal quality between the drone and the human gets too low, a new autonomous Crazyflie takes off and positions itself to relay the signal between the two agents and extends the exploration range for the human. Up to 15 autonomous drones can be part of the relay chain with the current implementation.

## Installation

### Cloning
This repository uses git submodules. Clone with the `--recursive` flag

```bash
git clone --recursive https://github.com/bitcraze/crazyflie-firmware.git
```

If you already have cloned the repo without the `--recursive` option, you need to 
get the submodules manually

```bash
cd crazyflie-firmware
git submodule init
git submodule update
```

### Installing dependencies
Please refer to the [original firmware's README](https://github.com/bitcraze/crazyflie-firmware) for installation instructions.

### config.mk
To create custom build options create a file called `config.mk` in the `tools/make/`
folder and fill it with options. E.g. 
```
PLATFORM=CF2
DEBUG=1
CLOAD=0
```

This fork doesn't use any particular options. `DEBUG=1` is recommended when modifying the firmware.

More information can be found on the [Bitcraze wiki](http://wiki.bitcraze.io/projects:crazyflie2:index)

## Compiling

This firmware was tested on Crazyflie 2.X drones. To build the firmware run ```make PLATFORM=cf2```. Crazyflie 2.X is the default build so just running ```make``` is enough.

## Folder description:
```
./              | Root, contains the Makefile
 + init         | Contains the main.c
 + config       | Configuration files
 + drivers      | Hardware driver layer
 |  + src       | Drivers source code
 |  + interface | Drivers header files. Interface to the HAL layer
 + hal          | Hardware abstraction layer
 |  + src       | HAL source code
 |  + interface | HAL header files. Interface with the other parts of the program
 + modules      | Firmware operating code and headers
 |  + src       | Firmware tasks source code and main.c
 |  + interface | Operating headers. Configure the firmware environment
 + tunnel       | Tunnel exploration code gathered as a separate module
 |  + src       | Exploration sources
 |  + interface | Exploration headers. tunnel_config.h has parameters that can be tweaked
 + utils        | Utils code. Implement utility block like the console.
 |  + src       | Utils source code
 |  + interface | Utils header files. Interface with the other parts of the program
 + platform     | Platform specific files. Not really used yet
 + tools        | Misc. scripts for LD, OpenOCD, make, version control, ...
 |              | *** The two following folders contains the unmodified files ***
 + lib          | Libraries
 |  + FreeRTOS  | Source FreeRTOS folder. Cleaned up from the useless files
 |  + STM32...  | Library folders of the ST STM32 peripheral libs
 |  + CMSIS     | Core abstraction layer
```
# Make targets:

Make details are available on the original README. This work has been developped by using 
```bash
make all flash
```
With an STLink v2 Debugger and the debug adapter kit from Bitcraze. Flashing through the Crazyradio with `make all cload` works but flashing fails have been observed using this method. 
