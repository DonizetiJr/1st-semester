#include <stdlib.h>
#include <stdio.h>

#define NUMELEMENTS 3

int main(int argc, char *argv[]) {
	int *ponteiro; // 8 bytes STACK
	int i; // 4 bytes STACK

	ponteiro = (int *) malloc(sizeof(int) * NUMELEMENTS);

	for (i = 0; i < NUMELEMENTS; i++) {
		ponteiro[i] = i+1;
	}

	for (i = 0; i < NUMELEMENTS; i++) {
		printf("Elemento na posicao %d da heap = %d (End elemento %p)\n", 
				i, ponteiro[i], &ponteiro[i]);
	}

	printf("\n\n");

	for (i = 0; i < NUMELEMENTS; i++) {
		printf("Elemento na posicao %d da heap = %d (End elemento %p)\n", 
				i, *(ponteiro+i), ponteiro+i);
	}

	printf("\n\nConteudo de ponteiro %p\n", ponteiro);
	ponteiro += 2;
	printf("Conteudo de ponteiro %p\n\n", ponteiro);

	for (i = 0; i < NUMELEMENTS; i++) {
		printf("Elemento na posicao %d da heap = %d (End elemento %p)\n", 
				i, *(ponteiro-i), ponteiro-i);
	}

	ponteiro -= 2;

	free(ponteiro);

	return 0;
}

/*
 		--------------
	X	|            |   HEAP
		|            |
		|            |
		|            |
		|            |
		|            |
		|            |
		|            |
	X+8	|            |
		|            |
		|            |
		|            |
		--------------
		|            |
		|            |
		|            |
		|            |
		|            |
		|            |
		|            |
		|            |
		|            |
		|            |
		|            |
		|            |
		|            |
		|            |
		|            |
		|            |
		|            |
		|            |
		|            |
		|            |
		|            |
		|            |
		|            |
		|            |
		|            | TOPO DA STACK
		|            |
		|            |
		|            |
		|            |
		|            |
		|            |
		|            |
		|            |
		|            |
		--------------
		|            |  main: i
		|            |
		|            |
		|            |
		--------------
		|            |  main: ponteiro
		|            |
		|            |
		|      X     |
		|            |
		|            |
		|            |
		|            | BASE DA STACK
		--------------
 */
