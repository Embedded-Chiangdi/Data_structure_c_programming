.PHONY = all clean

CC = gcc

#SRCS := $(wildcard *.c)
#BINS := $(SRCS:%.c=%)
BINS=single_list

all:$(BINS)

%:%.o
	@echo "Checking.."
	${CC} $< -o  $@
%.o:%.c
	@echo "Creating Object.."
	${CC} -c $<
clean:
	@echo "Clean up"
	rm -rvf *.o ${BINS}