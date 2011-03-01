#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FILE_SIZE (128 * 1024 * 1024)

int main(int argc, char** argv) {
	if (argc < 4) {
		return -1;
	}

	int iterations = atoi(argv[1]);
	int seed = atoi(argv[2]);
	int granularity = atoi(argv[3]);
	printf("building file of 128MB for %d iterations on seed %d with granularity %d\n", 
		iterations, seed, granularity);

	char* buffer = (char*)malloc(1024*1024);

	int i;
	FILE* f = fopen("READ.dat", "w+");
	for (i = 0; i < 128; i++) {
		fwrite(buffer, 1, 1024*1024, f);
	}

	srand(seed);
	printf("Running...\n");
	for (i = 0; i < iterations; i++) {
		int pos = rand() % (FILE_SIZE - granularity);
		fseek(f, pos, SEEK_SET);

		int read = fread(buffer, 1, granularity, f);
		if (read == granularity) {
			// success
		}
		else {
			// error reading
			printf("Error %d\n", read);
		}
	}
	printf("Done\n");
	fclose(f);

	return 0;
}
