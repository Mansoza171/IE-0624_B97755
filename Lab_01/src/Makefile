FAMILY=-mpic14
MCU=-p12f675
CC=sdcc
LD=sdcc
CFLAGS=-I. -I/usr/local/share/sdcc-4.0.0/share/sdcc/non-free
TARGET=lab1

SRCS = lab1.c

all:
	${CC} --use-non-free ${FAMILY} ${MCU} ${CFLAGS} -o ${TARGET} ${SRCS}
#	${LD} -o ${TARGET}.elf ${TARGET}.o
#	${OBJCOPY} -j .text -j .data -O ihex ${TARGET}.o ${TARGET}.hex
#	${SIZE} -C --mcu=${MCU} ${TARGET}.elf

clean:
	rm -f *.c~ *.h~ *.o *.elf *.hex *.asm
