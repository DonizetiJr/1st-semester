#include <stdlib.h>
#include <stdio.h>

// while (1) { printf("Hello World\n"); }
void recursao_de_cauda() {
	printf("Hello World\n");
	recursao_de_cauda();
}

// n = 5
// while (n > 0) { printf("Hello World\n"); n--; }
void recursao_de_cauda2(int n) {
	if (n == 0) return;	// caso base || critério de parada

	printf("Hello World: %d\n", n);

	recursao_de_cauda2(n-1);		// passo recursivo || recursão
}

/*
 		-----------------
		|		|
		|		|
		|		|
		|		|
		|		|
		|		|
		|		|
		|		|
		-----------------
		|		|
		|		|
		|	4	|  n
		|		|
		-----------------
		|		|
		|		|  END RET (return;)
		|		|
		|		|
		|		|
		|		|
		|		|
		|		|
		-----------------
		|		|
		|		|
		|	5	|	n
		|		|
		-----------------
		|		|  END RET (MAIN: return 0;)
		|		|
		|		|
		|		|
		|		|
		|		|
		|		|
		|		|
		-----------------
   */
int main(int argc, char *argv[]) {

	recursao2(atoi(argv[1]));

	return 0;
}
