#ifndef switches_included
#define switches_included
#include "msp430.h"

#define SW1 BIT0		/* switch1 is p2.0 */
#define SW2 BIT1		/* switch1 is p2.1 */
#define SW3 BIT2		/* switch1 is p2.2 */
#define SW4 BIT3		/* switch1 is p2.3 */

#define SWITCHES (SW1 | SW2 | SW3 | SW4)		/* only 1 switch on this board */

void switch_interrupt_handler();
void switch_init();
unsigned int p2sw_read();

extern char s_1, s_2, s_3, s_4;
extern char switch_state_down, switch_state_changed; /* effectively boolean */

#endif // included
