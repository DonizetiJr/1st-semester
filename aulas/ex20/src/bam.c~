// BAM -> Bidirectional Associative Memory
#include <stdlib.h>
#include <stdio.h>
#include <utils.h>
#include <string.h>
#include <preprocessing.h>
#include <matrix.h>

double **bam_training(double **allvectors, int nvectors, int length) {
	// allvectors (double **)
	//   |
	//   ----->   	double * --> -1 1 1 -1 ...
	//   		double *
	//   		double *
	//   		double *
	//   		double *
	//   		double *
	//   		double *
	
	// allvectors
	// -1 -1  1 1
	//  1 -1 -1 1
	//
	//  transpose(allvectors)
	// -1  1
	// -1 -1
	//  1 -1
	//  1  1
	double **Tallvectors;
	double **A;

	Tallvectors = matrix_transpose(allvectors, nvectors, length);
	// matriz de covariância
	A = matrix_multiplication(Tallvectors, length, nvectors, 
				  allvectors, nvectors, length);
	matrix_free(Tallvectors, length);

	return A;
}

// query é uma matrix que contém apenas uma linha
// 	em que essa linha contém a codificação da palavra em +1s e -1s
char *bam_testing(double **A, int nrow, int ncol, double **query) {
	double **response;
	char *string;
	int i = 0, j;

	do {
		response = matrix_multiplication(
					query, NUM_QUERY_VECTORS, nrow, 
					A, nrow, ncol);

		for (j = 0; j < nrow; j++) {
			if (response[FIRST_ROW][j] == 0) {
				response[FIRST_ROW][j] = 
					(rand() / (RAND_MAX*1.0)) - 0.5; //[-0.5,0.5]
			}
		}

		memcpy(query[FIRST_ROW], response[FIRST_ROW], 
					sizeof(double) * nrow);
		matrix_free(response, NUM_QUERY_VECTORS);
	} while (i++ < 10);

	string = vec2char(query[FIRST_ROW], nrow);
	//matrix_free(response, NUM_QUERY_VECTORS);

	return string;
}














