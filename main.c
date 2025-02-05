#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h> // Include for int8_t support
#include "./keyboard/keyboard.h" 
// #include "./avr_common/uart.h" // this includes the printf and initializes it

#define F_CPU 16000000UL
#define USART_BAUD_RATE 9600
#define UBRR_VALUE ((F_CPU / (16UL * USART_BAUD_RATE)) - 1)
#define COLS 4
#define ROWS 4
#define ALLOW_HOLD 1

void uart_init(void) {
    UBRR0H = (unsigned char)(UBRR_VALUE >> 8);
    UBRR0L = (unsigned char)UBRR_VALUE;
    UCSR0B = (1 << TXEN0) | (1 << RXEN0);
    UCSR0C = (3 << UCSZ00);
}

char keys[] = { '1', '2', '3', 'A', '4', '5', '6', 'B', '7', '8', '9', 'C', '*', '0', '#', 'D' };
int main(void) {
    uart_init();
    initKeyboardPortF(4, 4);
    while (1) {
      int index = scanKeyboardPortF(4, 4, 1);
      if (keys[index] == '2') {
        //Up
        uart_transmit(0x4C);
        uart_transmit(0x00);
        uart_transmit(0x20);
          _delay_ms(50);  
      }
      else if(keys[index] == '4') {

        //Left
        uart_transmit(0x43);
        uart_transmit(0x2A);
        uart_transmit(0x00);
          _delay_ms(50);  
      }
      else if(keys[index] == '8') {
                //down
        uart_transmit(0x40);
        uart_transmit(0x00);
        uart_transmit(0x2A);
          _delay_ms(50);  
      }
      else if(keys[index] == '6') {
         //right
        uart_transmit(0x40);
        uart_transmit(0x2A);
        uart_transmit(0x00);
          _delay_ms(50);  
      }
      else if(keys[index] == '1') {
         //right
        uart_transmit(0x60);
        uart_transmit(0x00);
        uart_transmit(0x00);
          _delay_ms(300);  

        uart_transmit(0x40);
        uart_transmit(0x00);
        uart_transmit(0x00);
      }
      else if(keys[index] == '3') {
         //right
        uart_transmit(0x50);
        uart_transmit(0x00);
        uart_transmit(0x00);
          _delay_ms(300);  

        uart_transmit(0x40);
        uart_transmit(0x00);
        uart_transmit(0x00);
      }
    }

    return 0;
}
