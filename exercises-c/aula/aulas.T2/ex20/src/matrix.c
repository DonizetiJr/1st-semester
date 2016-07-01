#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <matrix.h>

double **matrix_create(int row, int col) {
	double **m;
	int i;
	m = (double **) malloc(row * sizeof(double *));
	for (i = 0; i < row; i++)
		*(m+i) = (double *) calloc(col, sizeof(double));
	return m;
}

void matrix_free(double **m, int row) {
	int i;
	for (i = 0; i < row; i++) free(m[i]);
	free(m);
}

double **matrix_random(int row, int col, double min, double max) {
	int i, j;
	double **m;
	double rnd;

	if (min >= max) return NULL;

	srand(time(NULL));

	m = matrix_create(row, col);

	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			rnd = rand() / (RAND_MAX * 1.0); // [0,1]
			rnd *= (max-min); // [-1,1] => 2
			rnd += min;	  // [0,2] + min = [-1,1]
			m[i][j] = rnd;
		}
	}

	return m;
}

void matrix_printf(double **m, int row, int col) {
	int i, j;

	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++)
			printf("%lf\t", *(*(m+i)+j));
		printf("\n");
	}
}

void matrix_fprintf(FILE *fp, double **m, int row, int col) {
	int i, j;

	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++)
			fprintf(fp, "%lf\t", *(*(m+i)+j));
		fprintf(fp, "\n");
	}
}

void matrix_read(double **m, int row, int col) {
	int i, j;

	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++)
			scanf("%lf", &m[i][j]);
}

void matrix_fread(FILE *fp, double **m, int row, int col) {
	int i, j;

	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++)
			fscanf(fp, "%lf", &m[i][j]);
}

double **matrix_multiplication(double **m1, int row1, int col1,
			double **m2, int row2, int col2) {
	int i, j, k;
	double **mr;
	double sum;

	if (col1 != row2) return NULL;

	mr = matrix_create(row1, col2);

	for (i = 0; i < row1; i++) {
		for (j = 0; j < col2; j++) {
			sum = 0;
			for (k = 0; k < col1; k++) {
				sum += m1[i][k] * m2[k][j];
			}
			mr[i][j] = sum;
		}
	}

	return mr;
}

double **matrix_scalar_sum(double scalar, double **m, int row, int col) {
	int i, j;
	double **mr;

	mr = matrix_create(row, col);

	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			mr[i][j] = scalar + m[i][j];
		}
	}

	return mr;
}

double **matrix_scalar_mult(double scalar, double **m, int row, int col) {
	int i, j;
	double **mr;

	mr = matrix_create(row, col);

	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			mr[i][j] = scalar * m[i][j];
		}
	}

	return mr;
}

double **matrix_transpose(double **m, int row, int col) {
	int i, j;
	double **mr;

	mr = matrix_create(col, row);

	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			mr[j][i] = m[i][j];
		}
	}

	return mr;
}

void matrix_rref_mult(double scalar, double **mr, 
		int i, int col, double **identity) {
	int j;
	for (j = 0; j < col; j++) {
		mr[i][j] *= scalar;
		if (identity != NULL)
			identity[i][j] *= scalar;
	}
}

void matrix_rref_operation(double *mdstrow, 
			double scalar1, double *mrow1,
			double scalar2, double *mrow2, int col) {
	int i;
	for (i = 0; i < col; i++)
		mdstrow[i] = scalar1 * mrow1[i] + scalar2 * mrow2[i];
}

void matrix_swap_rows(double **m, int i, int j) {
	double *aux = m[i];
	m[i] = m[j];
	m[j] = aux;
}

boolean matrix_check_pivot(double **m, int i, int row, double **identity) {
	int j;
	double pivot;

	pivot = m[i][i];
	// Se pivot != 0, prossiga a execução
	if (pivot != 0) return TRUE;

	// Caso contrário, preciso trocar linhas...
	for (j = i+1; j < row; j++) {
		if (m[j][i] != 0) {
			// Encontrei uma linha em que o novo pivot != 0 ;)
			matrix_swap_rows(m, i, j);

			if (identity != NULL)
				matrix_swap_rows(identity, i, j);

			return TRUE;
		}
	}

	// Percorri todas as linhas e não há sequer 1 pivot != 0 :(
	return FALSE;
}

void matrix_zeroing_column(double **m, int i, int row, int col, double **identity) {
	int j;

	// Preciso percorrer todas as linhas desta coluna i
	for (j = 0; j < row; j++) {
		if (j != i && m[j][i] != 0) {
		   if (identity != NULL)
		   	matrix_rref_operation(identity[j], 
				-1*m[j][i], identity[i], 1, identity[j], col);
		   matrix_rref_operation(m[j], -1*m[j][i], m[i], 1, m[j], col);
		}
	}
}

double **matrix_copy(double **m, int row, int col) {
	int i, j;
	double **mcopy;

	mcopy = matrix_create(row, col);
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			mcopy[i][j] = m[i][j];
		}
	}

	return mcopy;
}

double **matrix_diag(double scalar, int n) {
	int i;
	double **diag;

	diag = matrix_create(n, n);

	for (i = 0; i < n; i++) {
		diag[i][i] = scalar;
	}

	return diag;
}

// row-reduced echelon form = escalonamento de matrix
double **matrix_rref(double **m, int row, int col, boolean inverse) {
	int i, j;
	double pivot;
	double **mr;
	double **identity = NULL;
	int mindimension;

	if (inverse && row == col) 
		identity = matrix_diag(1, row);
	else if (inverse) 
		return NULL;

	mr = matrix_copy(m, row, col);
	//mindimension = min(row, col);
	mindimension = row < col ? row : col; // operador ternário if

	for (i = 0; i < mindimension; i++) {
		// Verifique o pivot m[i][i]
		if (!matrix_check_pivot(mr, i, row, identity)) {
			if (!inverse)
				return mr;
			else {
				matrix_free(mr, row);
				return identity;
			}
		}
		pivot = mr[i][i];

		// Igualar o pivot a 1
		matrix_rref_mult(1/pivot, mr, i, col, identity);

		// Zerar demais elementos na mesma coluna
		matrix_zeroing_column(mr, i, row, col, identity);
	}

	if (!inverse)
		return mr;
	else {
		matrix_free(mr, row);
		return identity; // matrix inversa
	}
}







