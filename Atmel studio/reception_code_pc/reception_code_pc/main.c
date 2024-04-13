/*
 * reception_code_pc.c
 *
 * Created: 13/04/2024 17:33:24
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


void UART_Transmit(char data) {
	while (!(UCSR0A & (1 << UDRE0)));
	UDR0 = data;
}


int main(void) {
	UART_Init();
	
	while (1) {
		char received_string[1024];
		int index = 0;
		
		
		
		for (int i = 0; i < 1024; i++) {
			received_string[index++] = eeprom_read_byte(&Myvar[i]);
		}
		received_string[index] = '\0'; // Null-terminate the string

		
		for (int i = 0; received_string[i] != '\0'; i++) {
			UART_Transmit(received_string[i]);
		}
	}
	
	return 0;
}

