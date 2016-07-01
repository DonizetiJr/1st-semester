/*

				---------------
				|             |	   code segment
				---------------
				|             |
				---------------
				|             |    stack segment
				---------------
				|             |
				---------------
	0x7ffd8764a0cc		|             |   i
				|             |   
				|     0       |
				|             |
				---------------
		0x7ffd8764a0d0	|             |   result
				|             |
				|             | result[0]
				|             |
				---------------
				|             |
				|             |
				|             |  result[1]
				|             |
				---------------
				|             |
				|             |   result[2]
				|             |
				|             |
				---------------
				|             |
				|             |   result[3]
				|             |
				|             |
				---------------
				|             |
				|             |	  result[4]
				|             |
				|             |
				---------------
	0x7ffd8764a0e4		|             |   q
				|             |
				|   32765     |
				|             |
				---------------
	0x7ffd8764a0e8		|             |   r
				|      0      |
				|             |
				|             |
				---------------
	0x7ffd8764a0ec		|             |   n
				|             |
				|      0      |
				|             |     Fim da Stack
				---------------

 */

#include <stdio.h>

int main(int argc, char *argv[]) {

	int n;	// 4 bytes
	int r;	// 4 bytes
	int q;	// 4 bytes
	int result[5]; // 5 * 4 = 20 bytes
	int i;	// 4 bytes

	// result[0] => 4 bytes
	// result[1] => 4 bytes
	// result[2] => 4 bytes
	// result[3] => 4 bytes
	// result[4] => 4 bytes

	printf("Tamanho em bytes de n: %d\n", sizeof(n));
	printf("Tamanho em bytes de r: %d\n", sizeof(r));
	printf("Tamanho em bytes de q: %d\n", sizeof(q));
	printf("Tamanho em bytes de i: %d\n\n", sizeof(i));

	printf("Endereco da variavel n: %p\tValor: %d\n", &n, n);
	printf("Endereco da variavel r: %p\tValor: %d\n", &r, r);
	printf("Endereco da variavel q: %p\tValor: %d\n", &q, q);
	printf("Endereco da variavel result: %p\n", &result);
	printf("Endereco da variavel i: %p\tValor: %d\n\n", &i, i);

	for (i = 0; i < 5; i++) {
		printf("Endereco de result[%d] = %p\n", i, &result[i]);
	}

	// Parado
	for (;1 == 1;);

	return 0;
}











