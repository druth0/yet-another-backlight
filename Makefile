# yabl - yet another backlight

SRC = backlight.c lightcontrol.c

all: yabl

yabl:
	gcc backlight.c lightcontrol.c config.h lightcontrol.h -o $@

clean:
	rm -f yabl
