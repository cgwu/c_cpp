#include <iostream>
#include <cstdio>

#define println(...) printf(__VA_ARGS__)

int main(int argc, char** argv) {
	//println("HelloÖÐ¹ú\n");
	int a = 1, b = 2;
	int c = a <? b;
	printf("<?: %d\n", c);
	
	return 0;
}

