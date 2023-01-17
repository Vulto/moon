VERSION = 1.0
PREFIX = /home/vulto/C
BIN = moon

CC=gcc

sb-moon: moon.c
	cc -o moon moon.c 

install: moon 
	cp -f $(BIN) $(DESTDIR)$(PREFIX)/bin

clean:
	rm moon 
