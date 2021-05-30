CC=gcc
CFLAGS=-I.
DEPS = 
OBJ = quick_sort.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

quick_sort: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *.o

