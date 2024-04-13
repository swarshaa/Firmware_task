/*
 * Transmission_code_arduino.c
 *
 * Created: 13/04/2024 17:25:40
 * Author : Windows
 */ 


#include <avr/io.h>
#include <avr/eeprom.h>

#define F_CPU 16000000UL
#define BAUD 2400
#define UBRR_VALUE ((F_CPU / (16UL * BAUD)) - 1)
unsigned char EEMEM Myvar[1024]; 

void UART_Init() {
	UBRR0H = (unsigned char)(UBRR_VALUE >> 8);
	UBRR0L = (unsigned char)UBRR_VALUE;
	UCSR0B = (1 << RXEN0) | (1 << TXEN0);
	UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}

char UART_Receive() {
	while (!(UCSR0A & (1 << RXC0)));
	return UDR0;
}

int main(void) {
	UART_Init();

	while (1) {
		char received_string[1023];
		int index = 0;
		char received_char;
		do {
			received_char = UART_Receive();
			received_string[index++] = received_char;
		} while (received_char != '\n');
		received_string[index] = '\0'; 


		for (int i = 0; i < index; i++) {
			eeprom_write_byte(&Myvar[i], received_string[i]);
		}
		for (int i = 0; i < index; i++) {
			while (!(UCSR0A & (1 << UDRE0)));
			UDR0 = received_string[i]; // Transmit each character back
		}
	}

	return 0;
}
