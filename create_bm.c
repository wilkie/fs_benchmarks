#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char** argv) {
	if (argc < 2) {
		return -1;
	}

	int iterations = atoi(argv[1]);
	printf("running %d creates\n", iterations);

	int i;
	char* buffer = (char*)malloc(strlen(argv[1]) + 10);
	for (i = 0; i < iterations; i++) {
		sprintf(buffer, "FILE_%d.dat", i);

		FILE* f = fopen(buffer, "w+");
	}

	return 0;
}
