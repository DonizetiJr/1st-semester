/*
		-------------
	0	|           | Code segment
		-------------
	1	|           |
		-------------
	2	|           |
		-------------
	3	|           |
		-------------
	4	|           |
		-------------
	5	|           | Stack segment (Pilha) < 3MB
		-------------
		|           |
		-------------
		|           |
		-------------
		|           |  |
		-------------  |
		|           |  |
		-------------  | > q
		|           |  |
		-------------  |
		|           |  |
		-------------
		|           |  |
		-------------  |
		|           |  |
		-------------  | > n
		|           |  |
		-------------  |
		|           |  |
		-------------
		|           | Heap segment
		-------------
		|           |
		-------------
		|           |
		-------------
		|           |
		-------------
		|           |
		-------------
		|           |
		-------------

 *  ALGORITMO
 *  =========
 
 	1) Alguém me entrega um número decimal n	OK
	2) Verificar se n é divisível por 2
		2.1) sim
			n / 2 = q
			n - (2*q) = resto

			Volte para o passo 2 com n <- q (atribuição)
		2.2) não
			imprimir na tela resultado final
 */

#include <stdio.h>

int main(int argc, char *argv[]) {

	int n; // variável inteira -> 4 bytes
	int r;
	int q;

	printf("Digite um número decimal: "); // escreve na tela
 	// 1) Alguém me entrega um número decimal n	OK
	scanf("%d", &n); // leitura do teclado

	// transformar meu algoritmo em um programa em linguagem C
	// 2) Verificar se n é divisível por 2
	
	/* JUMP
passo2:
	if (n >= 2) {
		//2.1) sim
		q = n / 2; 	// q <- n / 2
		r = n - (2*q); 	// n - (2*q) = resto
		//	Volte para o passo 2 com n <- q (atribuição)
		goto passo2;

	} else {
		//2.2) não
		//	imprimir na tela resultado final
	}*/

	while (n >= 2) { 	// if seguido de goto
		q = n / 2; 	// q <- n / 2
		r = n - (2*q); 	// n - (2*q) = resto

		printf("Resto %d\n", r);

		n = q;		
	}

	// imprimir o resultado final
	printf("Último quociente %d\n", n);

	return 0;
}











