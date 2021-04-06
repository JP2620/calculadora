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

calc: calc.o suma.o asm_io.o
	$(CC) $(CFLAGS) -o $(BIN)/$@ $^

calc.o: calc.c asm_io.o
	$(CC) $(CFLAGS) -c $< -o $@

asm_io.o: asm_io.asm
	$(AS) $(ASFLAGS) -d ELF_TYPE $< -o $@

suma.o: suma.asm
	$(AS) $(ASFLAGS) -d ELF_TYPE $< -o $@

vpath test_%.h ./test/include
vpath test_%.c ./test/src

test: test_oper.o test_runner.o
	$(CC) $(CFLAGS) -o ./test/bin/$@ $^

test_%.o: test_%.c ./test/include/minuinit.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm *.o $(BIN)/* ./test/bin/*
