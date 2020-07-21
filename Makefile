# makfile configuration
COMMON_OBJECTS  = 
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -Os -Ih 
LDFLAGS		= -Llib -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as
AR 		= msp430-elf-ar

all: toy.elf 

#additional rules for files
toy.elf: ${COMMON_OBJECTS} p2_interrupt_handler.o buzzer.o led.o lcdLib/lcdutils.h  switches.o mainControl.o state_machine.o lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ -lLcd -lp2sw -lTimer

load: toy.elf
	msp430loader.sh toy.elf $^ 

clean: $^
	rm -f *.o *.elf *~ *#

