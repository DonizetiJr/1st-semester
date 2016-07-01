#include <stdio.h>
#include "matrix.h"

int main(int argc, char *argv[]) {
	double m[5][4]; // STACK 5 * 4 * 8 bytes = 160 bytes
	int i, j;

	printf("sizeof = %d\n", sizeof(m));

	matrix_read((double *) m, 5, 4);
	
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 4; j++) {
			printf("Endereço m[%d][%d] = %lf (%p)\n", i, j, 
					m[i][j], &m[i][j]);
		}
	}

	return 0;
}
