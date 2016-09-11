# Second -I should not be necessary; TODO: find a fix
FLAGS+= -Wall -I. -I/usr/include/lua5.1 -llua5.1 -lm -std=c99
EXEC=sona

SRCDESKTOP = $(wildcard src/*.c)
SRCMOBILE = $(wildcard src/*.c)

PREFIX?= /usr
BINDIR?= $(PREFIX)/bin

CC=gcc

all:
	@echo "Please specify what you want to build."
	@echo "Options are: desktop, mobile"

desktop: ${SRCDESKTOP}
	$(CC) ${SRCDESKTOP} -o ${EXEC} $(FLAGS)

mobile: ${SRCMOBILE}
	$(CC) ${SRCMOBILE} -o ${EXEC} $(FLAGS)

install: all
	install -Dm 755 sona $(DESTDIR)$(BINDIR)/sona

clean:
	rm -f sona *.o
