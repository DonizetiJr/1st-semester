#include <stdlib.h>
#include <stdio.h>

int **matrix_create(int n) {
	int i, j;
	int **m;
	m = (int **)calloc(n, sizeof(int *));
	
	for(i=0; i<n; i++) {
		m[i] = (int *)calloc(n, sizeof(int));
		for(j=0; j<n; j++) scanf("%d", &m[i][j]);
	}
	return m;
}

int check_rows(int **m, int n, int *row_sum) {
	int i, j;
	int *sum;

	sum = (int *)calloc(n, sizeof(int));

	for(j=0;j<n;j++) {
		for(i=0;i<n;i++) 
			sum[j] += m[j][i];
	}

	for(i=0;i<n-1;i++) {
		if(sum[i] != sum[i+1]) {
			free(sum);
			return 0;
		}
	}
	*row_sum = sum[0];
	free(sum);
	return 1;
}

int diag_sum1(int **m, int n) {
	int i, diag;

	diag = 0;
	for(i=0; i<n; i++) diag += m[i][i];
	return diag;
}

int diag_sum2(int **m, int n) {
	int i, diag;

	diag = 0;
	for(i=0; i<n; i++) diag += m[i][n-i-1];
	return diag;
}

int check_all(int **m, int n) {
	int i, diag1, diag2;
	int row_sum;

	if(!check_rows(m, n, &row_sum)) {
		printf("NAO\n");
		return -1;
	}

	diag1 = diag_sum1(m, n);
	diag2 = diag_sum2(m, n);

	if(diag1 == diag2 && diag2 == row_sum)
		printf("SIM\n");
	else
		printf("NAO\n");

	return 0;

}

int main(int argc, char *argv[]) {
	int n, i;
	int **matrix;
	
	scanf("%d", &n);
	matrix = matrix_create(n);
	check_all(matrix, n);

	for(i=0; i< n; i++) free(matrix[i]);
	free(matrix);
	return 0;
}