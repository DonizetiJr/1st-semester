#include <stdio.h>

union VAR {			// COMPARTILHAMENTO DE MEMORIA
	unsigned char a;	// 1 byte
	int b;			// 4 bytes
	double c;		// 8 bytes
	char *d;		// 8 bytes
};

/*
		-----------------	|
 		|		| --> a |
 		|		|	| > b
 		|		|	|
 		|		|
 		|		|
 		|		|
 		|		|
 		|		|
		-----------------
 */

int main(int argc, char *argv[]) {
	union VAR v;

	printf("Sizeof union = %d\n", sizeof(union VAR)); // 8 bytes

	v.d = NULL;
	printf("Char: %c\n", v.a);
	printf("Int: %d\n", v.b);
	printf("Double: %lf\n", v.c);
	printf("char*: %p\n\n", v.d);

	v.c = 346345.23636;
	printf("Char: %c\n", v.a);
	printf("Int: %d\n", v.b);
	printf("Double: %lf\n", v.c);
	printf("char*: %p\n", v.d);

	return 0;
}














