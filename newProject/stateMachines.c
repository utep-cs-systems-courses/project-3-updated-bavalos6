#include <msp430.h>
#include "stateMachines.h"
#include "led.h"

void dim(){
  red_on = 0;
  static int count = 6;
  
  if(count == 6){
    green_on = 1;
    count--;
    led_changed = 1;
    led_update();
  }
  
  else if(count == 0){
    count = 6;
  }

  else{
    green_on = 0;
    count--;
    led_changed = 1;
    led_update();
  }
}



