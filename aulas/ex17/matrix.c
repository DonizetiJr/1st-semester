#include <stdlib.h>
#include <stdio.h>

double **matrix_create(int row, int col) {
	double **m;
	int i;

	m = (double **) malloc(row * sizeof(double *));
	for (i = 0; i < row; i++) {
		//m[i] = (double *) malloc(col * sizeof(double));
		*(m+i) = (double *) calloc(col, sizeof(double));
	}

	return m;
}

void matrix_free(double **m, int row) {
	int i;
	for (i = 0; i < row; i++) free(m[i]);
	free(m);
}

void matrix_printf(double **m, int row, int col) {
	int i, j;

	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			//printf("%lf\t", m[i][j]);
			printf("%lf\t", *(*(m+i)+j));
		}
		printf("\n");
	}
}

void matrix_read(double *m, int row, int col) {
	int i, j;

	// a0,0
	// a0,1
	// a0,2
	// a0,3
	// a0,4
	// a1,0
	// a1,1	-> i=1, j=1	m+(1*5)+1 = m+6
	// a1,2
	// ...

	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			//scanf("%lf", &m[i][j]);
			//scanf("%lf", m[i]+j);
			//scanf("%lf", *(m+i)+j);
			scanf("%lf", m+(i*col)+j);
		}
	}
}

double **matrix_multiplication(double **m1, int row1, int col1,
			double **m2, int row2, int col2) {
	int i, j, k;
	double **mr;
	double sum;

	mr = matrix_create(row1, col2);

	// mr = m1 %*% m2
	for (i = 0; i < row1; i++) { // indexar as linhas de m1
		for (j = 0; j < col2; j++) { // indexar as colunas de m2
			// multiplicação dos termos
			sum = 0;
			for (k = 0; k < col1; k++) {
				sum += m1[i][k] * m2[k][j];
			}
			mr[i][j] = sum;
		}
	}

	return mr;
}
