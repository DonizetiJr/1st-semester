#include <stdlib.h>
#include <stdio.h>

#define NUMELEMENTS 10

int main(int argc, char *argv[]) {
	char *ponteiro;
	char *aux;
	int i;

	aux = (char *) malloc(sizeof(char) * NUMELEMENTS);
	ponteiro = aux;

	printf("Conteudo de ponteiro = %p (End %p)\n", ponteiro, &ponteiro);
	printf("Conteudo de aux = %p (End %p)\n\n", aux, &aux);

	for (i = 0; i < NUMELEMENTS; i++) {
		// opcao 1
		//
		// - pega o conteudo de aux
		// - me leva até esse endereço
		// - atribui a esse char o 'A'+i
		// - e por fim incrementa em 1 * sizeof(char) o conteudo de aux
		*aux++ = 'A' + i;
	}

	for (i = 0; i < NUMELEMENTS; i++) {
		printf("posicao %d = %c\n", i, *(ponteiro+i));
	}

	printf("Conteudo de ponteiro = %p (End %p)\n", ponteiro, &ponteiro);
	printf("Conteudo de aux = %p (End %p)\n", aux, &aux);

	free(ponteiro);

	return 0;
}
