CC            = gcc
CFLAGS        = -I.
OBJS          = *.o
BIN           = ./bin
HEADERS       = ./include
VPATH         = ./src

vpath %.h $(HEADERS)

calc: calc.o
	$(CC) -o $(BIN)/$@ $^
clean:
	rm *.o $(BIN)/*
