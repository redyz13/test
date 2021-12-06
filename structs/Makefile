CC=gcc
CFLAGS=-Wall -g
BIN =main.o persona.o

all: a.out 

a.out: $(BIN)
	$(CC) $(CFLAGS) -o $@ $^ 

main.o: main.c
	$(CC) $(CFLAGS) -c $< 

persona.o: persona.c persona.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm *.out *.o
