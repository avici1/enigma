CC = gcc
CFLAGS = -std=c11
SRCS = main.c rotor.c
OBJS = $(SRCS:.c=.o)

enigma: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o enigma

main.o: main.c rotor.h
	$(CC) $(CFLAGS) -c main.c

rotor.o: rotor.c rotor.h
	$(CC) $(CFLAGS) -c rotor.c

clean:
	rm -f $(OBJS) enigma
