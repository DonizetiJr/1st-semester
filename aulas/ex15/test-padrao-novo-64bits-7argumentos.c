#include <stdio.h>

int funcao(int a, int b, int c, int d, int e, int f, int g, int h) {
	int j;
}

int main(int argc, char *argv[]) {
	int a1 = 1;
	int b1 = 2;
	int c1 = 3;
	int d1 = 4;
	int e1 = 5;
	int f1 = 6;
	int g1 = 7;
	int h1 = 8;

	funcao(a1, b1, c1, d1, e1, f1, g1, h1);

	return 0;
}

/*	STACK novo padrão 64 bits ATÉ 6 argumentos para função
 *	======================================================
 
	GCC 5.3.0		

	arg: a
	arg: b
	arg: c
	arg: d
	arg: e
	arg: f
	funcao: j
	end ret			
	arg: g1
	main: g1		
	main: f1		
	main: e1		
	main: d1		
	main: c1		
	main: b1		
	main: a1
 */




