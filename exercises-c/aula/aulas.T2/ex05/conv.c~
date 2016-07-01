/*
 		STACK
		----------------
		|              |
		----------------
		|              |
		----------------
		|              |
		----------------
		|              |
		----------------
		|              |
		----------------
		|              |
		----------------
		|              |  int *result
		|              |
		|              |
		|  77cc        |
		|              |
		|              |
		|              |
		|              |
		----------------
		|              |  i
		|              |
		|              |
		|              |
		----------------
		|              |  q
		|              |
		|              |
		|              |
		----------------
		|              |  r
		|              |
		|              |
		|              |
		----------------
		|              |   n
		|              |
		|              |
		|              | FIM DA STACK
		----------------
		|              |
		----------------
		|              |
		----------------
		|              |
		----------------
		|              |
		----------------
		|              |
		----------------
		|              |
		----------------
77cc		|              |   Heap segment
		|    15        |
		|              |  => result[0]
		|              |
		----------------
		|              |
		|              |
		|              |   => result[1]
		|              |
		----------------
		|              |
		|              |
		|              |   => result[2]
		|              |
		----------------
		|              |
		|     7        |
		|              |   => result[3]
		|              |
		----------------
		|              |
		|              |   => result[4]
		|              |
		|              |   FIM DA HEAP
		----------------
		|              |
		----------------
		|              |
		----------------
		|              |
		----------------
		|              |
		----------------
		|              |
		----------------
		|              |
		----------------
		|              |
		----------------
		|              |
		----------------
		|              |
		----------------
		|              |
		----------------
		|              |
		----------------
		|              |
		----------------
		|              |
		----------------
		|              |
		----------------
		|              |
		----------------
		|              |
		----------------
		|              |
		----------------
		|              |
		----------------
		|              |
		----------------
		|              |
		----------------
		|              |
		----------------
		|              |
		----------------
		|              |
		----------------
		|              |
		----------------
		|              |
 */
#include <stdio.h>

int main(int argc, char *argv[]) {

	int n;	// 4 bytes
	int r;	// 4 bytes
	int q;	// 4 bytes
	int i;	// 4 bytes
	int *result; // 8 bytes

	// Alocando memória Heap
	result = (int *) malloc(sizeof(int) * 5);
	result[0] = 15;
	result[3] = 7;

	free(result); // liberando a Heap

	printf("Tamanho em bytes de n: %d\n", sizeof(n));
	printf("Tamanho em bytes de r: %d\n", sizeof(r));
	printf("Tamanho em bytes de q: %d\n", sizeof(q));
	printf("Tamanho em bytes de i: %d\n\n", sizeof(i));

	printf("Endereco da variavel n: %p\tValor: %d\n", &n, n);
	printf("Endereco da variavel r: %p\tValor: %d\n", &r, r);
	printf("Endereco da variavel q: %p\tValor: %d\n", &q, q);
	printf("Endereco da variavel result: %p\n", &result);
	printf("Endereco da variavel i: %p\tValor: %d\n\n", &i, i);

	for (i = 0; i < 5; i++) {
		printf("Endereco de result[%d] = %p\n", i, &result[i]);
	}

	// Parado
	for (;1 == 1;);

	return 0;
}











