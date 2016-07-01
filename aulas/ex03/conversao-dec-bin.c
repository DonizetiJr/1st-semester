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
	6	|           |
		-------------
	7	|           |
		-------------
	8	|   00110111|  |		&result	-> 8
		-------------  |		&result[0] -> 8
	9	|   00000000|  |		&result[1] -> 12
		-------------  |		result[0] = 55;
	10	|   00000000|  |
		-------------  |
	11	|   00000000|  |
		-------------  |
	12	|           |  |
		-------------  |
	13	|           |  |
		-------------  |
	14	|           |  |
		-------------  |
	15	|           |  |
		-------------  |
	16	|           |  |
		-------------  |
	17	|           |  |
		-------------  |
		|           |  |
		-------------  |
		|           |  |
		-------------  | > result
		|           |  |
		-------------  |
		|           |  |
		-------------  |
		|           |  |
		-------------  |
		|           |  |
		-------------  |
		|           |  |
		-------------  |
		|           |  |
		-------------  |
		|           |  |
		-------------  |
		|           |  |
		-------------
		|           |  |
		-------------  |
		|           |  |
		-------------  | > r
		|           |  |
		-------------  |
		|           |  |
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

	int n, r, q;
	int result[5]; // 5 * 4 = 20 bytes
	int i;

	/*
	result[0] = 1
	result[1] = 
	// ...
	result[4] = 
	*/

	printf("Digite um número decimal: "); 
	scanf("%d", &n); 

	i = 0;
	for (; i < 5;) { // mesmo comportamento do while
		result[i] = 0;
		i++;
	}

	i = 0;
	while (n >= 2) { 	
		q = n / 2; 	
		r = n - (2*q); 	
		result[i] = r;
		i++; // i = i + 1;
		n = q;		
	}
	result[i] = n;

	// inversão???
	// result -> 0 1 0 0 1
	/*
	i = 4;
	printf("%d", result[i]);
	i = 3;
	printf("%d", result[i]);
	i = 2;
	printf("%d", result[i]);
	i = 1;
	printf("%d", result[i]);
	i = 0;
	printf("%d", result[i]);
	*/
	for (i = 4; i >= 0; i--) {
		printf("%d", result[i]);
	}

	return 0;
}











