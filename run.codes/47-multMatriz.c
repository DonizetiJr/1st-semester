#include <stdio.h>
#include <stdlib.h>


int **recMatrix(int row, int col) {
	int i, j;
	int **mat;
	mat = (int **)malloc(row*sizeof(int *));
	for(i=0; i<row; i++) {
		mat[i] = (int *)malloc(col*sizeof(int)); 
		for(j=0; j < col; j++) scanf("%d", &mat[i][j]);
	}
	return mat;
}

void multMatrix(int col1, int col2, int row1, 
						int row2, int **matrix1, int **matrix2) {
	int i, j, k;
	int sum;
	int **matrixR;

	for (i = 0; i < row1; i++) {
		for (j = 0; j < col2; j++) {
			sum = 0;
			for (k = 0; k < col1; k++) 
				sum += matrix1[i][k] * matrix2[k][j];
			printf("%d ", sum);
		}
		printf("\n");
	}		
}

void matrixFree(int **mat, int row) {
	int i;
	for (i = 0; i < row; i++) free(mat[i]);
	free(mat);
}

int main(int argc, char *argv[]) {

	int col1, col2, row1, row2;
	int **matrix1, **matrix2;
	
	scanf("%d %d", &row1, &col1);
	matrix1 = recMatrix(row1, col1);
	
	scanf("%d %d", &row2, &col2);
	matrix2 = recMatrix(row2, col2);

	multMatrix(col1, col2, row1, row2, matrix1, matrix2);

	matrixFree(matrix1, row1);
	matrixFree(matrix2, row2);

	return 0;
}