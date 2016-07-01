#ifndef _MATRIX_H_
#define _MATRIX_H_

//.h -> header file (arquivo cabeçalho)
double **matrix_create(int, int);
void matrix_free(double **, int);
void matrix_printf(double **, int, int);
void matrix_read(double *, int, int);
double **matrix_multiplication(double **, int, int, double **, int, int);

#endif
