.PHONY=all clean hello

CC = gcc

SRCS := $(wildcard *.c)
BINS := $(SRCS:%.c=%)

all:${BINS}
%:%.c
	@echo "compiling..."
	${CC} $< -o $@ -g
clean:
	@echo "clean ${BINS}"
	@rm -rf ${BINS}
hello:
	@echo "This is a Makefile for String"