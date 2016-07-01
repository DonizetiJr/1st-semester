#include <stdlib.h>
#include <stdio.h>
#include <matrix.h>

#define ROWS 8
#define COLS 8

#define MIN_VALUE -1
#define MAX_VALUE  1

enum {
	PROGNAME, // 0
	KEYFILE,  // 1
	NARGS     // 2
};

int main(int argc, char *argv[]) {
	double **K;
	FILE *fpkey;

	if (argc != NARGS) {
		printf("usage: %s keyfile\n", argv[PROGNAME]);
		return -1;
	}

	// Gerando a matriz de números aleatórios
	K = matrix_random(ROWS, COLS, MIN_VALUE, MAX_VALUE);

	// Salvar em arquivo...
	fpkey = fopen(argv[KEYFILE], "w+");
	if (fpkey == NULL) {
		printf("Could not open keyfile: %s\n", argv[KEYFILE]);
		return -2;
	}
	matrix_fprintf(fpkey, K, ROWS, COLS);
	fclose(fpkey);

	matrix_free(K, ROWS);

	return 0;
}














