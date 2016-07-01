#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

// create vector
int *create_vector(int n) {
	int i;
	int *vector = (int *) malloc(sizeof(int) * n);

	for (i = 0; i < n; i++) vector[i] = i+1;

	return vector;
}

//////////////////// VERSAO RECURSIVA ///////////////////////
// busca binária (pois o vetor está ordenado!!!!)
int busca_binaria_recursiva(int *vector, int start, int end, int key) {
	if (start > end) return -1; // caso base ou condicao de parada da recursao
	int middle = (end + start) / 2;
	if (key == vector[middle]) 
		return middle;
	else if (key > vector[middle])
		return busca_binaria_recursiva(vector, middle+1, end, key);
	else return busca_binaria_recursiva(vector, start, middle-1, key);
}

//////////////////// VERSAO ITERATIVA ////////////////////////
int busca_binaria_iterativa(int *vector, int n, int key) {
	int start = 0, end = n-1;
	int middle;
	while (start <= end) {
 		middle = (end + start) / 2;
		if (key == vector[middle]) return middle;
		if (key > vector[middle]) start = middle + 1;
		else end = middle - 1;
	}
	return -1;
}

int main(int argc, char *argv[]) {
	int i, key, val, n;
	int *vector;
	clock_t start, end;
	double time;

	for (n = (int) pow(2,3); n <= (int) pow(2,29); n*=2) {
 		vector = create_vector(n);

		start = clock();
		for (i = -1; i <= n; i++) {
			key = i+1;
			val = busca_binaria_recursiva(vector, 0, n-1, key);
			//printf("Encontrei??? %d\n", val);
		}
		end = clock();

		time = (end-start) / (CLOCKS_PER_SEC * 1.0);

		printf("%d\t%lf\n", n, time);

		free(vector);
	}

	return 0;
}









