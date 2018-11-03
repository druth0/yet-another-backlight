# yabl - yet another backlight

SRC = backlight.c lightcontrol.c
OBJ = ${SRC:.c=.o}

all: yabl

.c.o:
	gcc -c $<
${OBJ}: config.h lightcontrol.h

yabl: ${OBJ}
	gcc -o $A ${OBJ}

clean:
	rm -f yabl ${OBJ}
