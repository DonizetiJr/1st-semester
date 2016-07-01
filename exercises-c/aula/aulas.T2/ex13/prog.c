#include <stdio.h>

// Registrador EAX -> 8 bytes
int *create_vector(int n) {
	int i; // STACK		4 bytes
	int array[n]; // STACK	n * sizeof(int)

	for (i = 0; i < n; i++) {
		printf("Endereco de array[%d] => %p\n", i, &array[i]);
		array[i] = i;
	}

	// ****************
	// Desenhar até aqui!!!
	// ****************

	return array;
}

int main(int argc, char *argv[]) {
	int n; // STACK 4 bytes
	int total; // STACK 4 bytes
	int *retorno; // STACK 8 bytes

	printf("Endereco de n => %p\n", &n);
	printf("Endereco de total => %p\n", &total);
	printf("Endereco de retorno => %p\n", &retorno);

	scanf("%d", &n);
	int array[n];

	retorno = create_vector(n); // EAX -> retorno

	for (total = 0; total < n; total++) {
		array[total] = retorno[total];
	}

	for (total = 0; total < n; total++) {
		printf("%d", array[total]);
	}

	return 0;
}

/*
 
Endereco de n => 0x7ffc41d330cc
Endereco de total => 0x7ffc41d330c8
Endereco de retorno => 0x7ffc41d330c0
5
Endereco de array[0] => 0x7ffc41d33040
Endereco de array[1] => 0x7ffc41d33044
Endereco de array[2] => 0x7ffc41d33048
Endereco de array[3] => 0x7ffc41d3304c
Endereco de array[4] => 0x7ffc41d33050

		STACK

		-------------
		|           |
		|           |
		|           |
		|           |
		|           |
		|           |
		|           |
		-------------
	50	|           |   create_vector: int array[3]
	51	|    0      |
	52	|           |
	53	|           |
		-------------
	54	|           |
	55	|    1      |
	56	|           |
	57	|           |
		-------------
	58	|           |
	59	|    2      |
	60	|           |
	61	|           |
		-------------
	62	|           |   create_vector: i
	63	|    3      |
	64	|           |
	65	|           |
		-------------
		|           |  endereço de retorno da função create_vector
		|           |
		|           |
		|           |
		|    Y      |
		|           |
		|           |
		|           |
		-------------
		|           |  argumento: create_vector: int n
		|    3      |
		|           |
		|           |
		-------------
	Er	|           |  main: retorno    <---------------
		|           |
		|           |
		|           |
		|           |
		|           |
		|           |
		|           |
		-------------
	Et	|           |  main: total
		|           |
		|           |
		|           |
		-------------
	En	|           |  main: n
		|     3     |
		|           |
		|           |
		-------------

 */














