CC=gcc
CFLAGS=-Wall -Wextra -std=c99

SRC=$(wildcard *.c)
OBSJ=$(SRCS:%.c=%.o)
TARGETS=$(OBJS:%.o=%)

build:
	gcc -Wall -Wextra -std=c99 *.c -o tema1

pack:
	zip -FSr 312CA_SpinochiAndreea_Tema1.zip README Makefile *.c *.h

clean:
	rm -f $(TARGETS) $(OBJS)

.PHONY: pack clean