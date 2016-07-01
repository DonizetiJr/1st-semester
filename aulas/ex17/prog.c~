#include <stdio.h>  // procure no diretório /usr/include
#include "matrix.h" // procure no diretório local

int main(int argc, char *argv[]) {
	double **m1;
	double **m2;
	double **mr;

	m1 = matrix_create(3, 4);
	m2 = matrix_create(4, 2);

	printf("Preencha a matrix m1\n");
	matrix_read(m1, 3, 4);

	printf("\nPreencha a matrix m2\n");
	matrix_read(m2, 4, 2);

	mr = matrix_multiplication(m1, 3, 4, m2, 4, 2);
	printf("Resultado...\n\n");
	matrix_printf(mr, 3, 2);

	matrix_free(m1, 3);
	matrix_free(m2, 4);
	matrix_free(mr, 3);

	return 0;
}
