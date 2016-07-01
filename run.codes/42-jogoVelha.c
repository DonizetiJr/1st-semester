#include <stdlib.h>
#include <stdio.h>

#define SIZE 3
#define FIRST 1
#define SECOND -1

int **create_board() {
	int i, row, col, round;
	int **m;
	
	m = (int **)malloc(sizeof(int)*SIZE);
	for(i=0; i < SIZE; i++) 
		m[i] = (int *)calloc(SIZE, sizeof(int));

	round = 1;
	while(scanf("%d %d", &row, &col) != EOF) {
		m[row][col] = round*1;
		round = round*-1;
	}

	return m;
}

int check_rows(int **m) {
	int i, j, sum;
	
	for(i=0; i < SIZE; i++) {
		sum = 0;
		for(j=0; j < SIZE; j++) sum += m[i][j];
		if(sum == SIZE) return 1;
		else if(sum == (-1)*SIZE) return -1;
	}
	return 0;
}

int check_cols(int **m) {
	int j, i, sum;
	
	for(j=0; j < SIZE; j++) {
		sum = 0;
		for(i=0; i < SIZE; i++) sum += m[i][j];
		if(sum == SIZE) return 1;
		else if(sum == (-1)*SIZE) return -1;
	}
	return 0;
}

int check_diags(int **m) {
	int i, sum;
	
	sum = 0;
	for(i=0; i < SIZE; i++)	sum += m[i][i];

	if(sum == SIZE) return 1;
	else if(sum == (-1)*SIZE) return -1;

	//Secondary Diag:
	sum = 0;
	for(i=0; i < SIZE; i++) sum += m[i][SIZE-i-1];

	if(sum == SIZE) return 1;
	else if(sum == (-1)*SIZE) return -1;

	return 0;	
}

void final_result(int **m) {
	int rows, cols, diags;

	rows = check_rows(m);
	cols = check_cols(m);
	diags = check_diags(m);

	if(rows == 1) printf("0");
		else if(rows == -1) printf("1");

	else if(cols == 1) printf("0");
		else if(cols == -1) printf("1");

	else if(diags == 1) printf("0");
		else if(diags == -1) printf("1");

	else 
		printf("empate");
}

void free_board(int **board) {
	int i;

	for(i=0; i < SIZE; i++) free(board[i]);
		free(board);
}

int main(int argc, char *argv[]) {
	int **board;

	board = create_board();
	final_result(board);

	free_board(board);

	return 0;
}