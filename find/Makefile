
TARGETS := static_seq_find.out static_seq_find2.out

all: $(TARGETS)

%.out: %.c
	gcc -g -std=c99 $< -o $@

.PHONY: clean
clean:
	rm -rf *.out
	rm -rf *.o

