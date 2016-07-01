#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void swap(int *vector, int i, int j) {
	int aux = vector[i];
	vector[i] = vector[j];
	vector[j] = aux;
}

int *createVector(int n, int sorted) {
	int *vector; // STACK 8 bytes
	int i; // STACK 4 bytes
	int j; // STACK 4 bytes

	srand(time(NULL)); // seed rand

	// HEAP 4 * n bytes
	vector = (int *) malloc(sizeof(int) * n);

	// gera o vetor com elementos 1, 2, 3, ..., n
	for (i = 0; i < n; i++)
		vector[i] = i+1;

	if (!sorted) {
		// aleatorizar o vetor
		for (i = 0; i < n; i++) {
			// elemento da posicao i
			// elemento da posicao j
			j = rand() % n; // j = {0, 1, 2, ..., n-1}
			// % operador de mod (resto de divisão)
			swap(vector, i, j);
		}
	}

	return vector;
}

int sequentialSearch(int *vector, int n, int key) {
	int i;

	for (i = 0; i < n; i++)
		if (vector[i] == key) return i;
	return -1;
}

int binarySearch(int *vector, int n, int key) {
	int middle;
	int start, end;

	start = 0;
	end = n-1;

	while (start <= end) {
		middle = (end + start) / 2;

		if (vector[middle] == key) {
			return middle;
		} else if (key < vector[middle]) {
			end = middle - 1;
		} else { // if (key > vector[middle]) {
			start = middle + 1;
		}
	}
	
	return -1;
}

int main(int argc, char *argv[]) {
	int *vector; // STACK 8 bytes
	int n; // STACK 4 bytes
	int key; // STACK 4 bytes
	int pos; // STACK 4 bytes

	if (argc != 3) {
		printf("usage: %s <number of elements> <key>\n", argv[0]);
		return 1;
	}

	// char *argv[] -> char **argv
	// char *x -> x[0] ???
	// char **y -> y[0] ???
	n = atoi(argv[1]); // char *
	key = atoi(argv[2]); // char *

	printf("Criando vetor...\n");
	vector = createVector(n, 1);

	printf("Procurando chave = %d\n", key);
	//pos = sequentialSearch(vector, n, key);
	pos = binarySearch(vector, n, key);
	printf("Chave %d encontrada em %d\n", key, pos);

	free(vector);

	return 0;
}













