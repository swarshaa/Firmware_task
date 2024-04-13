Project Title: UART Serial Communication between PC and MCU


This project demonstrates the use of UART serial communication between a PC and an MCU to transmit and receive data using Atmel studio,Platform.io. The Python script running on the PC sends data to the MCU, which then sends data back to the PC.The MCU used consists of Atmega328P processor.



Requirements

1.Arduino UNO board
2.USB cable for connecting the Arduino UNO to the PC
3.Visual studio code
4.Atmel studio 7
5.Extensions required:
      a.Platform.io
      b.Python
      c.c/c++
6.PySerial library installed on the PC

Procedure

Note:Connect the MCU to the PC using a USB cable.

a.Atmel studio:
  step 1:Set up atmel studio 7 for the connected MCU
  step 2:open the Transmission_code_arduino by using open project build it and upload to arduino 
  step 3:open pccode.py in vscode and run (select option 1)
                *The script will transmit the data to MCU and print the transmission speed.*
  step 4:open the reception_code_pc by using open project build it and upload to arduino
  step 5:open pccode.py in vscode and run (select option 2)
                *The Python script will receive the acknowledgment and print the receiving speed.*
  step 6:UART serial communication between a PC and an MCU is easteblished successfully and transmission and reception of data has completed  using Atmel studio



b.Platform.io:
  step 1:Set up platform.io in vscode download the extension and restart the vscode
  step 2:open arduinocode.cpp in platform.io workspace
  step 3:build and upload it into arduino
  step 4:open pccode.py in vscode and run
                *The python script will transmit the data to MCU and print the transmission speed and the Python script will receive the acknowledgment and print the receiving speed.*
  step 5:UART serial communication between a PC and an MCU is easteblished successfully and transmission and reception of data has completed  using Platform.io

