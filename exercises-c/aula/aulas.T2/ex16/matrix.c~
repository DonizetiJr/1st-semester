#include <stdio.h>

int main(int argc, char *argv[]) {
	// Inteiramente na STACK
	int i;
	int matrix[50][100]; // 50x100 -> 4 bytes = 20.000 bytes
	int **matrix_legal = NULL; // 8 bytes da STACK

	matrix_legal = (int **) malloc(50 * sizeof(int *));
	for (i = 0; i < 50; i++) {
		matrix_legal[i] = (int *) malloc(100 * sizeof(int));
	}

	for (i = 0; i < 50; i++) free(matrix_legal[i]);
	free(matrix_legal);

	return 0;
}
