CC=gcc-12
CFLAGS=-I. -std=c99
DEPS = hanoi.h pile.h
OBJ = hanoi.o main.o pile.o

%.o: %.c $(DEPS)
	$(CC) -c  -o $@ $< $(CFLAGS)

hanoi: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)