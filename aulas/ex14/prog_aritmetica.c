#include <stdlib.h>
#include <stdio.h>

/*
 		------------
 	x-8	|          |  ponteiro
 		|          |
 		|          |
 		|    10    |
 		|          |
 		|          |
 		|          |
 		|          |
 		------------
 	X	|          | variavel
 		|          |
 		|          |
 		|          |
 		------------
 */

int main(int argc, char *argv[]) {
	int variavel; // 4 bytes STACK
	int *ponteiro;// 8 bytes STACK

	ponteiro = &variavel;
	printf("Conteudo de ponteiro %p e o endereco do ponteiro %p\n", 
			ponteiro, &ponteiro);
	printf("Conteudo de variavel %d e o endereco de variavel %p\n\n", 
			variavel, &variavel);

	printf("Conteudo de memoria para o qual o ponteiro aponta %d\n", *ponteiro);

	(*ponteiro)++;
	printf("\n%d\t%d\n\n", variavel, *ponteiro);

	*ponteiro = 10;
	printf("%d\t%d\n\n", variavel, *ponteiro);

	//ponteiro = 10;
	//printf("%d\n\n", *ponteiro); // segmentation fault (acesso indevido
					// à memória

	// IMPOSSIVEL!!!
	//free(ponteiro);

	return 0;
}











