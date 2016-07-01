/*
0) Para j = 1 até numerodeelementos-1, j++
	1) Para i = 0 até numerodeelementos-j, i++
		2) comparar v[i] > v[i+1]
			- trocar v[i] com v[i+1]
		- Volte para o passo 1
	   - Volte para o passo 0
 */

#include <stdlib.h>
#include <stdio.h>

// 5, 3, 1, 2, 7, -6
int veclen(int *vector) {
	int i = 0;
	while (vector[i] >= 0) i++;
	return i;
}

void print(int *vector, int len) {
	int i;
	for (i = 0; i < len; i++)
		printf("%d\n", vector[i]);
	printf("\n");
}

int *readVector() {
	int value;
	int *vector = NULL;
	int counter = 0;

	do {
		scanf("%d", &value);
		vector=(int*)realloc(vector, sizeof(int) * (counter+1));
		vector[counter++] = value;
	} while (value >= 0);

	return vector;
}

void sort(int *vector, int len) {
	int i, j, aux;
	// contador = 0;

	for (j = 1; j < len; j++) {
		for (i = 0; i < len-j; i++) {
			// contador++
			if (vector[i] > vector[i+1]) {
				aux = vector[i];
				vector[i] = vector[i+1];
				vector[i+1] = aux;
			}
		}
	}

	// qual o valor de contador para vector de qualquer tam?
	return;
}

int main(int argc, char *argv[]) {
	int *v;
	int l;

	v = readVector();	/*
					readVector();
					v = EAX;
				   */
	l = veclen(v);
	print(v, l);
	sort(v, l);
	print(v, l);

	free(v);

	return 0;
}

/*
 		--------------
	X	|            |  HEAP
		|            |
		|     3      |
		|            |
 		--------------
		|            |
		|     7      |
		|            |
		|            |
 		--------------
		|            |
		|            |
		|    -8      |
		|            |
 		--------------
		|            |
 
  		STACK
 		--------------
		|            |
 		--------------
		|            |
 		--------------
		|            |
 		--------------
		|            |
 		--------------
		|            | main: int l
		|            |
		|            |
		|            |
 		--------------
		|            | main: int *v
		|            |
		|            |
		|      X     |
		|            |
		|            |
		|            |
		|            |
 		--------------
		|            |  End de ret da main
		|            |
		|            |
		|            |
		|            |
		|            |
		|            |
		|            |
 		--------------
		|            |   argumentos da main	FIM STACK
 		--------------

 */
