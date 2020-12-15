#include <msp430.h>
#include "stateMachineBuzz.h"
#include "buzzer.h"
#include "switches.h"
#include "lcdutils.h"
#include "lcddraw.h"

char Horizontal = 1;
char Right = 1;
int tColor = COLOR_RED;
int rColor = COLOR_BLUE;
char* str = " ";

void buttonBuzzer(){
  if(s_1){
    arreglo = &ruidosLocos[0];
    Right = !Right;
    str = "> SWAP";
  }
  else if(s_2){
    arreglo = &ruidosLocos2[0];
    Horizontal = !Horizontal;
    str = ">ORIENTATION";
  }
  else if(s_3){
    arreglo = &ruidosLocos3[0];
    int temp = tColor;
    tColor = rColor;
    rColor = temp;
    str = ">COLOR";
  }
  else if(s_4){
    arreglo = &ruidosLocos4[0];
    clearScreen(COLOR_WHITE);
    str = "CLEAR";
  }
}
