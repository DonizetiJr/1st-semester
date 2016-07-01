#include <stdlib.h>
#include <stdio.h>

void passagem_por_valor(double *ponteiro) {
	printf("\tAntes = %p\n", ponteiro);
	ponteiro = (double *) malloc(8);
	printf("\tDepois = %p\n", ponteiro);
}

void passagem_por_referencia(double **ponteiro) {
	printf("\tAntes = %p\n", *ponteiro);
	*ponteiro = (double *) malloc(8);
	printf("\tDepois = %p\n", *ponteiro);
}

int main(int argc, char *argv[]) {
	double *ponteiro = NULL;

	printf("main: Antes = %p\n", ponteiro);
	passagem_por_referencia(&ponteiro);
	printf("main: Depois = %p\n", ponteiro);
	free(ponteiro);

	return 0;
}

/*
		------------
   	X	|          | main: double *ponteiro
   		|          |
   		|          |
   		|    0xFF  |
   		|          |
   		|          |
   		|          |
   		|          |
   		------------

*/

