#include <util/delay.h>
#include <stdio.h>
#include "./avr_common/uart.h" // this includes the printf and initializes it
#include "keyboard.h" 
#include <avr/io.h>
#include <stdint.h>
#include <stdio.h>

int scanKeyboardPortF(int cols, int rows, int allowHold){
	for (uint8_t row = 0; row < rows; row++) {
		PORTF = ~(1 << row);
		_delay_us(100);
		uint8_t colInput = (PINF >> 4) & 0x0F;
		for (uint8_t col = 0; col < cols; col++) {
			if (!(colInput & (1 << col))) { 
				if(!allowHold)
					while (!(PINF & (1 << (col + 4))));
				return row*cols + col;
			}
		}
	}
	return -1;
}

void initKeyboardPortF(int rows, int cols) {
    DDRF |= 0x0F;
    DDRF &= ~0xF0;
    PORTF |= 0xF0;
}