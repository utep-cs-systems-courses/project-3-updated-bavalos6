#include <msp430.h>
#include "libTimer.h"
#include "led.h"
#include "buzzer.h"
#include "lcdutils.h"
#include "lcddraw.h"
#include "stateMachineBuzz.h"
#include "led_assembly.h"
#include "switches.h"

int redrawScreen = 1;

int main(void) {
  configureClocks();		/* setup master oscillator, CPU & peripheral clocks */
  lcd_init();
  led_init();
  switch_init();
  enableWDTInterrupts();	/* enable periodic interrupt */
  or_sr(0x8);
  
  for(;;) { 
    while (!redrawScreen) { /**< Pause CPU if screen doesn't need updating */
      or_sr(0x10);	      /**< CPU OFF */
    }
    redrawScreen = 0;
   
    clearScreen(COLOR_WHITE);
    if(Horizontal){
      drawString5x7(53, 10, str, COLOR_BLACK, COLOR_WHITE);
    }
    else{
      drawString5x7(53, 79, str, COLOR_BLACK, COLOR_WHITE);
    }
    if(*str != 'C'){
      drawTriangle(Right, Horizontal, tColor);
      drawRectangle(!Right, Horizontal, rColor);  
    }
  }
}

/** Watchdog timer interrupt handler. 15 interrupts/sec */
void wdt_c_handler()
{
  static char blink_count = 0;
  static short count = 0;
  
  if (++blink_count == 20 && (i <= 5 )) {
    buzzer_play_sound();
    blink_count = 0;
  }
  /* if(i< 5 && i>0){
    dim();
    }*/

  count ++;
  if (count == 1) {
    if (switch_state_down){
      redrawScreen = 1;
    }
    count = 0;
  }
}
