CC = clang
CFLAGS = -O2 -Wall -Wno-unused

module = main.o

all: $(module)
	$(CC) $(CFLAGS) -o main $(module)

main.o: main.c vector_template.h list_template.h library.h
	$(CC) $(CFLAGS) -c main.c

.PHONY: clean clean-object
clean:
	-rm main $(module)
clean-object:
	-rm $(module)
