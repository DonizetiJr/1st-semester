#include <stdio.h>

// 2 tipos:
// 	1. passagem de argumentos via valor (por valor)
// 	2. passagem de argumentos via referência (por referência)

void passagem_por_valor(int counter) {
	printf("\tCounter antes = %d\n", counter);
	counter++;
	printf("\tCounter depois = %d\n", counter);
}

void passagem_por_referencia(int *counter) {
	printf("\tCounter antes = %d\n", *counter);
	(*counter)++;
	printf("\tCounter depois = %d\n", *counter);
}

int main(int argc, char *argv[]) {
	int counter = 0;

	printf("main: antes = %d\n", counter);
	//passagem_por_valor(counter);
	passagem_por_referencia(&counter);
	printf("main: depois = %d\n", counter);

	return 0;
}

/*
 		STACK padrão antigo

		-----------
	X	|         | main: counter
		|  1      |
		|         |
		|         |
		-----------

 */
