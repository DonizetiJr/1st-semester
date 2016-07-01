#ifndef _MATRIX_H_
#define _MATRIX_H_

#define min(r,c) r < c ? r : c

typedef enum {
	FALSE, // 0
	TRUE   // 1
} boolean;

//.h -> header file (arquivo cabeçalho)
double **matrix_create(int, int);
void matrix_free(double **, int);
double **matrix_random(int, int, double, double);
void matrix_printf(double **, int, int);
void matrix_read(double **, int, int);
double **matrix_multiplication(double **, int, int, double **, int, int);
double **matrix_scalar_sum(double, double **, int, int);
double **matrix_scalar_mult(double, double **, int, int);
double **matrix_transpose(double **, int, int);
double **matrix_copy(double **, int, int);
double **matrix_diag(double, int);
double **matrix_rref(double **, int, int, boolean);

#endif
