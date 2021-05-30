CC=gcc
CFLAGS=-I.
DEPS = 
OBJ = find_nth.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

find_nth: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *.o

