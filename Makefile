CC            = gcc
CFLAGS        = -m32
AS		:= nasm
ASFLAGS := -f elf

OBJS          = *.o
BIN           = ./bin
HEADERS       = ./include
VPATH         = ./src

vpath %.h $(HEADERS)
vpath %.asm ./src

all: calc test

calc: calc.o suma.o resta.o asm_io.o
	$(CC) $(CFLAGS) -o $(BIN)/$@ $^

calc.o: calc.c asm_io.o
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.asm
	$(AS) $(ASFLAGS) -d ELF_TYPE $< -o $@

vpath test_%.h ./test/include
vpath test_%.c ./test/src

test: test_oper.o test_runner.o suma.o
	$(CC) $(CFLAGS) -o ./test/bin/$@ $^

test_%.o: test_%.c ./test/include/minuinit.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm *.o $(BIN)/* ./test/bin/*
