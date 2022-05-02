RM := rm -rf

SRC := $(wildcard ./src/*.c)

CC ?= gcc

C_FLAGS := -Wall -Wextra

ifeq ($(CC),clang)
	C_FLAGS += -Weverything
endif

all: main.out

main.out:
	$(CC) $(C_FLAGS) -Iinc ./app/main.c $(SRC) -o $@

clean:
	$(RM) main.out
