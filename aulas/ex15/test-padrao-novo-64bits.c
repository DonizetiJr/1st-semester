#include <stdio.h>

int funcao(int a, int b) {
	int c;

}

int main(int argc, char *argv[]) {
	int a = 1;
	int b = 2;

	funcao(a, b);

	int c = 5;

	return 0;
}

/*	STACK novo padrão 64 bits ATÉ 6 argumentos para função
 *	======================================================
 
	GCC 5.3.0			GCC 4.8.4

	arg a				arg b
	arg b				arg a
	end ret				end ret
	main: b				main: a
	main: a				main: b
 */




