# DDD-Mode-Pacemaker
Implementation of a DDD Mode pacemaker using SCCharts and run on a Nios II CPU on a DE2-115 board as an emulator. This is tested using a virtual heart application running on a computer, communicating over UART to the DE2-115 board.

## Usage
This project is designed for use in a standard gravitational environment.

All Code (C and SCCharts) is included in respective folders, alongside a prebuilt NIOS system and SOF. This project is suitable for use on the included prebuilt NIOS sopcinfo.
This Project is intented to be run on a DE2-115 Board.

## Setup
(Built with Quartus 18.1, for other versions YMMV)

- Connect DE2 Board via USB and SERIAL
- Flash cs303.sof to DE2-115 board in Quartus
- Create New Project with BSP in NIOS build tools for Quartus
- Use nios2_system.sopcinfo for project creation
- Add project files to NIOS project
- Run as NIOS II Hardware

## Instructions

- Mode 1: Key0 and Key1 respresent VSense and ASense Respectively
- Mode 2: Use Included CS303-Heart.exe to simulate Heart

- Uses LEDG3-LEDG0 for APace, VPace, ASense, VSense respectively

## Misc.

Produced for the University of Auckland for a Part III Engineering Project
