
TARGETS := merge.out util.o selection.out

all: $(TARGETS)

merge.out: merge.c util.o
	gcc -g -Wall -std=c99 merge.c util.o -o $@
selection.out: selection.c util.o
	gcc -g -Wall -std=c99 merge.c util.o -o $@
util.o: util.c util.h
	gcc -g -Wall -std=c99 -c $<

.PHONY: clean
clean:
	rm -rf *.out
	rm -rf *.o
