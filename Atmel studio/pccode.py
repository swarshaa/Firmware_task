import serial
import time

def serial_connection_eastablish(port, baudrate):
    try:
        serialport = serial.Serial(port, baudrate) 
        print("Serial connection established successfully.")
        return serialport
    except serial.SerialException:
        print("Failed to establish serial connection. Please check if the device is connected or the port is correct.")
        return None

def transmit_data(serialport, data):
    print("Transmitting data from PC to UNO\n")
    start_time = time.time()
    total_bytes_sent = 0

    for byte in data:
        serialport.write(bytes([byte]))
        total_bytes_sent += 1
        elapsed_time = time.time() - start_time

        if elapsed_time > 0:
            transmissionspeed = total_bytes_sent * 8 / elapsed_time
            print("Transmission_Speed: {:.2f} bits/second".format(transmissionspeed))
        else:
            continue
    print("\n**********data transmitted from PC to UNO**********\n")

def receive_data(serial_port, data_length):
    start_time_reception = time.time()
    reception_time_interval = 1 

    received_string = ""
    print("Receive data from UNO to PC")

    while True:
        if serial_port.in_waiting > 0:
            received_data = serial_port.read(serial_port.in_waiting)
            received_string += received_data.decode()
            elapsed_time_reception = time.time() - start_time_reception

            if elapsed_time_reception >= reception_time_interval:
                receiving_speed = len(received_string) * 8 / elapsed_time_reception
                print("Reception_Speed: {:.2f} bits/second".format(receiving_speed))
                start_time_reception = time.time()

        if len(received_string) >= data_length:
            break

    print("\nReceived Data:\n")
    print(received_string)
    print("\n**********data transmitted from UNO to PC**********\n")

def main():
    res=int(input())
    serialport = serial_connection_eastablish('COM8', 2400)
    if serialport is None:
        return

    with open('Data.txt', 'rb') as file:
            data_to_send = file.read()

            
    time.sleep(2)
    if res==1 :
        

        transmit_data(serialport, data_to_send)
        time.sleep(2)
    elif res==2:
        receive_data(serialport, len(data_to_send))

    serialport.close()

if __name__ == "__main__":
    main()
