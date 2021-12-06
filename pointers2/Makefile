CC=gcc
CFLAGS=-Wall -g
BIN =a.o b.o tu.o

all: a.out b.out tu.out

a.out: a.o 
	$(CC) $(CFLAGS) -o $@ $<

b.out: b.o 
	$(CC) $(CFLAGS) -o $@ $< 

tu.out: tu.o 
	$(CC) $(CFLAGS) -o $@ $< 

a.o: a.c
	$(CC) $(CFLAGS) -c $< 

b.o: b.c 
	$(CC) $(CFLAGS) -c $<

tu.o: tu.c 
	$(CC) $(CFLAGS) -c $<

clean:
	rm *.out *.o
