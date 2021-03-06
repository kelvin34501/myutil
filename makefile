CC = clang
CFLAGS = -pthread -g -Wall -Wno-unused -std=gnu11

module = main.o graph.o string_util.o
header = vector_template.h list_template.h binarytree_template.h \
	set_template.h map_template.h ntree_template.h graph_template.h \
	library.h

all: $(module)
	$(CC) $(CFLAGS) -o main $(module)

main.o: main.c $(header)
	$(CC) $(CFLAGS) -c main.c

graph.o: graph.c graph.h vector_template.h
	$(CC) $(CFLAGS) -c graph.c

string_util.o: string_util.c string_util.h
	$(CC) $(CFLAGS) -c string_util.c

.PHONY: clean clean-object
clean:
	-rm main $(module)
clean-object:
	-rm $(module)
