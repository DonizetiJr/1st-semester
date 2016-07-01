#include <stdio.h>

/*
matrix[0][0] 0x7ffea3aceaf0	-> m[0]
matrix[0][1] 0x7ffea3aceaf4	-> m[1]
matrix[0][2] 0x7ffea3aceaf8	-> m[2]
matrix[0][3] 0x7ffea3aceafc	-> m[3]
matrix[1][0] 0x7ffea3aceb00	-> m[4]
matrix[1][1] 0x7ffea3aceb04	-> m[5]
matrix[1][2] 0x7ffea3aceb08
matrix[1][3] 0x7ffea3aceb0c
matrix[2][0] 0x7ffea3aceb10
matrix[2][1] 0x7ffea3aceb14
matrix[2][2] 0x7ffea3aceb18
matrix[2][3] 0x7ffea3aceb1c	-> m[11]
*/
void funcao(int *m, int row, int col) {
	int i, j;

	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			printf("m[%d][%d] %p\n", i, j, &m[i*col+j]);
		}
	}
}

int main(int argc, char *argv[]) {
	int matrix[3][4]; // STACK  3 * 4 * 4 bytes = 48 bytes
	int i, j;
	
	funcao((int *) matrix, 3, 4);

	/*
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 4; j++) {
			printf("matrix[%d][%d] %p\n", i, j, 
					&matrix[i][j]);
		}
	}
	*/

	return 0;
}
