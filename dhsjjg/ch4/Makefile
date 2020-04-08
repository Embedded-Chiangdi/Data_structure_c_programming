.PHONY=all clean hello

CC= gcc

SRCS := $(wildcard *.c)
BINS := $(SRCS:%.c=%)

all:${BINS}
%:%.c
	@echo "Compiling...."
	${CC} $< -o  $@
clean:
	@echo "clean:${BINS}"
	@rm -rf ${BINS} 
hello:
	@echo "Hello This is a Makefile"