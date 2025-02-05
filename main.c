#include <util/delay.h>
#include <stdio.h>
#include "./avr_common/uart.h" // this includes the printf and initializes it
#include "./keyboard/keyboard.h" 
#include <stdint.h>

#define COLS 4
#define ROWS 4
#define ALLOW_HOLD 1


int main(void){
  char keys[] = { '1', '2', '3', 'A', '4', '5', '6', 'B', '7', '8', '9', 'C', '*', '0', '#', 'D' };

  printf_init(); 
  initKeyboardPortF(COLS, ROWS);

  while (1) {
      int index = scanKeyboardPortF(COLS, ROWS, ALLOW_HOLD);
      if (index != -1) {
          printf("Key pressed: %c\n", keys[index]);
          _delay_ms(50);  
      }
  }
}
