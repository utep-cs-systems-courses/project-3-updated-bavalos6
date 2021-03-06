#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "stateMachineBuzz.h"
#include "buzzer.h"
#include "lcdutils.h"
#include "lcddraw.h"
#include "libTimer.h"

char switch_state_down, switch_state_changed; /* effectively boolean */
char s_1, s_2, s_3, s_4; //Switches 
static unsigned char switches_last_reported;
static unsigned char switches_current;

static char 
switch_update_interrupt_sense()
{
  char p2val = P2IN;
  switches_current = P2IN & SWITCHES;
  /* update switch interrupt to detect changes from current buttons */
  P2IES |= (switches_current);	/* if switch up, sense down */
  P2IES &= (switches_current | ~SWITCHES);	/* if switch down, sense up */
  return p2val;
}

void 
switch_init()			/* setup switch */
{  
  P2REN |= SWITCHES;		/* enables resistors for switches */
  P2IE = SWITCHES;		/* enable interrupts from switches */
  P2OUT |= SWITCHES;		/* pull-ups for switches */
  P2DIR &= ~SWITCHES;		/* set switches' bits for input */
  switch_update_interrupt_sense();
}

unsigned int p2sw_read(){
  unsigned int sw_changed = switches_current ^ switches_last_reported;
  switches_last_reported = switches_current;
  return switches_current | (sw_changed << 8);
}

void __interrupt_vec(PORT2_VECTOR) Port_2(){
  if (P2IFG & SWITCHES){  /* Did a button cause this interrupt? */
    P2IFG &= ~SWITCHES;   /* Clear pending sw interrupts*/
    switch_interrupt_handler(); /*Single handler for all switches*/
  }
}

void
switch_interrupt_handler()
{
  char p2val = switch_update_interrupt_sense();
  s_1 = (p2val & SW1) ? 0:1;
  s_2 = (p2val & SW2) ? 0:1;
  s_3 = (p2val & SW3) ? 0:1;
  s_4 = (p2val & SW4) ? 0:1;
  switch_state_down = (s_1 || s_2 || s_3 || s_4);
  if(switch_state_down){
    buttonBuzzer();
    buzzer_init();
    /* green_on = 1;
    red_on = 0;
    led_changed = 1;
    switch_state_changed = 1;
    led_update();*/ 
  }
}

