
TARGETS := merge.out util.o selection.out heap.out bubble.out quick.out

all: $(TARGETS)

util.o: util.c util.h
	gcc -g -Wall -std=c99 -c $<

merge.out: merge.c util.o
	gcc -g -Wall -std=c99 $< util.o -o $@
selection.out: selection.c util.o
	gcc -g -Wall -std=c99 $< util.o -o $@
heap.out: heap.c util.o
	gcc -g -Wall -std=c99 -lm $< util.o -o $@
bubble.out: bubble.c util.o
	gcc -g -Wall -std=c99 -lm $< util.o -o $@
quick.out: quick.c util.o
	gcc -g -Wall -std=c99 -lm $< util.o -o $@

.PHONY: clean
clean:
	rm -rf *.out
	rm -rf *.o
