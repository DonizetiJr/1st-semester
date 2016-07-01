








#include <stdio.h>

int main(int argc, char *argv[]) {
	char c; // 1 byte STACK

	// Two's complement => Complemento de dois
	//
	// POSITIVOS
	// 00000000
	// 00000001
	// 00000010
	// 00000011
	// 00000100
	// ...
	// 01111111 => 127
	//
	// NEGATIVOS
	// 10000000
	// 10000001
	// 10000010
	// 11111111

	for (c = 0; c < 255; c++) {
		printf("%c\t%d\n", c, c);
	}

	return 0;
}
