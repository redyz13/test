CC=gcc
CFLAGS=-Wall -g
BIN = forno.o

all: forno.out 

forno.out: $(BIN)
	$(CC) $(CFLAGS) -o $@ $^ 

forno.o: forno.c
	$(CC) $(CFLAGS) -c $< 

spazzacenere:
	rm *.out *.o
