# makfile configuration
COMMON_OBJECTS  = 
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h -L/opt/ti/msp430_gcc/include
LDFLAGS		= -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: labFile.elf 

#additional rules for files
labFile.elf: ${COMMON_OBJECTS} lcdutils.o font-5x7.o lcddraw.o buzzer.o switches.o led_assembly.o stateMachineBuzz.o mainFile.o led.o ../shape-motion-demo/wdt_handler.o ../lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: labFile.elf
	msp430loader.sh  $^

clean: $^
	rm -f *.o *.elf




