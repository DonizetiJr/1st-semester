#include <stdio.h>
#include "matrix.h"

int main(int argc, char *argv[]) {
	double **A;
	double **Ainv;
	double **Ainv2;

	printf("A:\n");
	A = matrix_random(3,3,-1,1);
	matrix_printf(A,3,3);

	printf("\nInverse:\n");
	Ainv = matrix_rref(A, 3, 3, TRUE);
	matrix_printf(Ainv,3,3);

	printf("\nInverse of Inverse:\n");
	Ainv2 = matrix_rref(Ainv, 3, 3, TRUE);
	matrix_printf(Ainv2,3,3);

	matrix_free(A, 3);
	matrix_free(Ainv, 3);
	matrix_free(Ainv2, 3);

	return 0;
}
