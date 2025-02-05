#include "uart.h"
// ********************************************************************************
// Includes
// ********************************************************************************
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <stdbool.h>
// ********************************************************************************
// Macros and Defines
// ********************************************************************************
#define F_CPU 16000000UL
#define BAUD 9600
#define MYUBRR ((F_CPU / (16UL * BAUD)) - 1)

void uart_init(void) {
    UBRR0H = (unsigned char)(MYUBRR >> 8);
    UBRR0L = (unsigned char)MYUBRR;
    UCSR0B = (1 << TXEN0) | (1 << RXEN0);
    UCSR0C = (3 << UCSZ00);
}

void uart_transmit(uint8_t data) {
    while (!(UCSR0A & (1 << UDRE0)));
    UDR0 = data;
}

void uart_transmit_int8(int8_t data) {
    uart_transmit((uint8_t)data); // Send as raw byte
}