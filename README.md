# Project Title: UART Serial Communication between PC and MCU

## Overview
This project demonstrates the use of UART serial communication between a PC and an MCU to transmit and receive data using Atmel Studio and Platform.io. The Python script running on the PC sends data to the MCU, which then sends data back to the PC. The MCU used consists of Atmega328P processor.

## Requirements
- Arduino UNO board
- USB cable for connecting the Arduino UNO to the PC
- Visual Studio Code
- Atmel Studio 7
- Extensions required:
  - Platform.io
  - Python
  - C/C++
- PySerial library installed on the PC

## Procedure
**Note: Connect the MCU to the PC using a USB cable.**

### Atmel Studio
- Set up Atmel Studio 7 for the connected MCU.
- Open the `Transmission_code_arduino` by using open project, build it, and upload to Arduino.
- Open `pccode.py` in VSCode and run (select option 1).
  - The script will transmit the data to MCU and print the transmission speed.
- Open the `reception_code_pc` by using open project, build it, and upload to Arduino.
- Open `pccode.py` in VSCode and run (select option 2).
  - The Python script will receive the acknowledgment and print the receiving speed.
- UART serial communication between a PC and an MCU is established successfully, and transmission and reception of data have completed using Atmel Studio.

### Platform.io
- Set up Platform.io in VSCode, download the extension, and restart VSCode.
- Open `arduinocode.cpp` in Platform.io workspace.
- Build and upload it into Arduino.
- Open `pccode.py` in VSCode and run.
  - The Python script will transmit the data to MCU and print the transmission speed, and the Python script will receive the acknowledgment and print the receiving speed.
- UART serial communication between a PC and an MCU is established successfully, and transmission and reception of data have completed using Platform.io.
