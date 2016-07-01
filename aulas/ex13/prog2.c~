#include <stdio.h>

// Registrador EAX -> 8 bytes
int *create_vector(int n) {
	int i; // STACK		4 bytes
	int array[n]; // STACK	n * sizeof(int)

	for (i = 0; i < n; i++) {
		printf("Endereco de array[%d] => %p\n", i, &array[i]);
		array[i] = i;
	}
	return array;
}

int *print_vector(int n) {
	int i; // STACK		4 bytes
	int array[n]; // STACK	n * sizeof(int)

	while (i > 0) {
		printf("%d\n", array[--i]);
	}

	return NULL;
}

int main(int argc, char *argv[]) {
	int a,b,c,d,e,f;
	int n;
	int total;
	int *retorno;

	scanf("%d", &n);

	retorno = create_vector(n); // EAX -> retorno
	//printf("MEU QUERIDO PRINTF :) %d%d%d%d%d%d\n\n", 
	//		a, b, c, d, e, f); -> 15 args
	print_vector(n);

	return 0;
}





