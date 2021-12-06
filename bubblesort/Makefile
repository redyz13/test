CC=gcc
CFLAGS=-Wall -g
BIN =main.o arrfunc.o

all: a.out 

a.out: $(BIN)
	$(CC) $(CFLAGS) -o $@ $^ 

main.o: main.c
	$(CC) $(CFLAGS) -c $< 

arrfunc.o: arrfunc.c arrfunc.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm *.out *.o
