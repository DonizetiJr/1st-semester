/*
 		STACK
		--------------
		|            |
		--------------
30		|            |  ponteiro
		|            |
		|            |
		|            |
		|   3c       |
		|            |
		|            |
		|            |
		--------------
38		|            |  b
		|    11      |
		|            |
		|            |
		--------------
3c		|            |  a
		|    10      |
		|            |
		|            |
		--------------
*/

#include <stdio.h>

int main(int argc, char *argv[]) {
	int a;		// 4 bytes
	int b;		// 4 bytes
	int *ponteiro;	// 8 bytes

	printf("Endereco a: %p\tTamanho: %d\n", &a, sizeof(a));
	printf("Endereco b: %p\tTamanho: %d\n", &b, sizeof(b));
	printf("Endereco ponteiro: %p\tTamanho: %d\n", 
				&ponteiro, sizeof(int *));

	a = 10;
	b = 11;

	ponteiro = &a;  // atribuir o endereco da variavel a para
			// o ponteiro

	printf("Valor contido em a = %d\n", a);
	printf("Valor contido no endereco para o qual o ponteiro aponta = %d\n\n", *ponteiro);

	ponteiro = &b;
	printf("Valor contido em a = %d\n", a);
	printf("Valor contido no endereco para o qual o ponteiro aponta = %d\n\n", *ponteiro);

	return 0;
}









