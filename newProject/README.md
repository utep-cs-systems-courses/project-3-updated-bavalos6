## Description of Lab 2
Lab 2 consists in state machines programmed to make the switches play
different songs depending on the state we are located on. When a song is being
played the green led will flash and will dim while the song is being played
and right when the song ends the green led will turn off and red led wil turn on.

File                  | Description
--------------------- | -----------
buzzer.c              | Stores arrays with notes (array = song) for each switch and has iterates through each note 
led_assembly.s        | A state machine that dims the light when the song is playing. (Assembly Language)
led.c 	              | Updates the leds and turns on or off the leds.
mainFile.c            | Initializes the leds, the interrupts, and the switches.
p1_interrupt_handler.c| Reads the switches from the P2 Dir.
stateMachineBuzz.c    | State machine that assigns a song to each switch.
stateMachines.c       | A state machine that dims the light when the song is playing. 
switches.c            | Receives input from the switched pressed and updates led and does button buzzer.
wdInterruptHandler.c  | Timer which performs the dim method and plays notes when the amount of interrupts. 

## How to Use

The Makefile in this direcory contains rules to run the Makefile in each demo directory. Use **make** in this directory to build all demo programs and the timer library. Once the programs are built, you can load the program onto the MSP430 by changing into the corresponding demo directory and using **make load**.

You may use **mspdebug rf2500 "erase"** to clear a program from the MSP430.

You can also get rid of the **.o** programs by typing **make clean**
