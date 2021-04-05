CC            = gcc
CFLAGS        = -I.
OBJS          = *.o
BIN           = ./bin
HEADERS       = ./include
VPATH         = ./src

vpath %.h $(HEADERS)

calc: calc.o
	$(CC) -o $(BIN)/$@ $^

calc.o: calc.c
	$(CC) -c $< -o $@

vpath test_%.h ./test/include
vpath test_%.c ./test/src

test: test_oper.o test_runner.o
	$(CC) -o ./test/bin/$@ $^

test_%.o: test_%.c ./test/include/minuinit.h
	$(CC) -c $< -o $@

clean:
	rm *.o $(BIN)/* ./test/bin/*
