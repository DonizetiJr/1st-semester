#include <stdio.h> // incluir standard input and output library

int main(int argc, char *argv[]) {

	int numero;	// 32 bits	->	32 / 8 = 4 bytes
	char caracter;	// 8 bits	-> 	1 byte

	numero = 56;
	caracter = 'a';

	printf("Numero: %d   Caracter: %c\n", numero, caracter);

	return 0;
}
