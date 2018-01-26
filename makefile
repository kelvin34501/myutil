CC = clang
CFLAGS = -g -Wall -Wno-unused

module = main.o
header = vector_template.h list_template.h binarytree_template.h set_template.h map_template.h string_util.h library.h

all: $(module)
	$(CC) $(CFLAGS) -o main $(module)

main.o: main.c $(header)
	$(CC) $(CFLAGS) -c main.c

.PHONY: clean clean-object
clean:
	-rm main $(module)
clean-object:
	-rm $(module)
