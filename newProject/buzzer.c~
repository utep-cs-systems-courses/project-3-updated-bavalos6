#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "led.h"

int ruidosLocos[] = {0, 7644, 6811, 6067, 5102, 5102, 4545, 5102, 6067, 7644, 6811, 6067, 6067, 6811, 7644, 6811, 6811, 0};
int ruidosLocos2[]= {0, 4290, 3822, 3608, 4290, 2863, 2863, 3214, 4816, 4290, 3822, 4816, 3214, 3214, 3608, 3822, 4290, 0};
int ruidosLocos3[]= {0, 1351, 1804, 5406, 1351, 1804, 5406, 1351, 1804, 5406, 1351, 1804, 5406, 1351, 1804, 5406, 1351, 0};
int ruidosLocos4[]= {0, 1136, 1351, 1517, 5102, 0, 1703, 0, 1136, 1351, 1517, 4050, 0, 1703, 0, 1703, 1517, 0};
int *arreglo;
int i = 0;

void buzzer_init()
{
    /* 
       Direct timer A output "TA0.1" to P2.6.  
        According to table 21 from data sheet:
          P2SEL2.6, P2SEL2.7, anmd P2SEL.7 must be zero
          P2SEL.6 must be 1
        Also: P2.6 direction must be output
    */
    timerAUpmode();		/* used to drive speaker */
    P2SEL2 &= ~(BIT6 | BIT7);
    P2SEL &= ~BIT7; 
    P2SEL |= BIT6;
    P2DIR = BIT6;		/* enable output to speaker (P2.6) */
    i = 0;
    buzzer_play_sound();
}

void buzzer_set_period(short cycles) /* buzzer clock = 2MHz.  (period of 1k results in 2kHz tone) */
{
  CCR0 = cycles; 
  CCR1 = cycles >> 1;		/* one half cycle */
}

void buzzer_play_sound(){
  buzzer_set_period(arreglo[i]);
  if(i >= 14){
    red_on = 1;
    green_on = 0;
    led_changed = 1;
    led_update();
  }
}
    
    
  

