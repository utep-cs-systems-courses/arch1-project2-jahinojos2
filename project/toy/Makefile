# makefile configuration

COMMON_OBJECTS 	=
CPU 		= msp430g2553
CFLAGS 		= -mmcu=${CPU} -I../h
LDFLAGS		= -L/opt/ti/msp430_gcc/include

#switch the compiler (fpr the internal make rules)

CC	= msp430-elf-gcc
AS	= msp430-elf-as -mcpu=msp430 --traditional-format -mP

all: button.elf

#additional rules
button.elf:${COMMON_OBJECTS} stateMachines.o wdInterruptHandler.o p2_interrupt_handler.o led.o buzzer.o switches.o main.o stateMachines_asse.o ../lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: button.elf
	msp430loader.sh button.elf

clean:
	rm -f *.o *.elf
