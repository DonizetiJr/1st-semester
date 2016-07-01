#include <stdlib.h>
#include <stdio.h>


	/*
			|	|
			|	|
			|	|
			|	|
			|	|
			|	|
			|	|
			|	|
			|	|
			|	|
			|	|
			|	|
			|	|
			|	|
			|	|
			|	|
			|	|
			|	|
			|	|
			|	|
			|	|
			|	|
			|	|
			|	|
			|	|
			|	|
			|	|
			|	|
			|	|
			|	|
			|	|
			|	|
			|	|
			|	|
			|	|
			|	|
			|	|
			|	|
			|	|
			|	|
			|	|
			|	|
			|	|
			|	|
			|	|
			|	|
			|	|
			---------
			|	|
			|   0   | n
			|	|
			|	|
			---------
			|	|
			|	|
			|	|
			|	|  end ret
			|	|
			|	|
			|	|
			|	|
			---------
			|	|
			|   1   | n
			|	|
			|	|
			---------
			|	|
			|	|
			|	|
			|	|  end ret
			|	|
			|	|
			|	|
			|	|
			---------
			|	|
			|   2   | n
			|	|
			|	|
			---------
			|	|
			|	|
			|	|
			|	|  end ret
			|	|
			|	|
			|	|
			|	|
			---------
			|	|
			|   3   | n
			|	|
			|	|
			---------
			|	|
			|	|
			|	|
			|	|  end ret
			|	|
			|	|
			|	|
			|	|
			---------
			|	|
			|   4   | n
			|	|
			|	|
			---------
			|	|
			|	|
			|	|
			|	|  end ret
			|	|
			|	|
			|	|
			|	|
			---------
			|	|
			|	|
			|   5   |  n
			|	|
			---------
			|	|
			|	|
			|	|
			|	|
			|	|
			|	|
			|	|
			|	|  end ret (main)
			---------
	 */



// DEFINICAO
//
//	n == 0		n! = 1
//	n > 0		n * (n-1)!
//
int fatorial(int n) {
	int ret;

	if (n == 0) return 1; 		// caso base

	printf("%d\n", n);
	ret = fatorial(n-1);	// passo recursivo
	printf("%d\n", ret);

	return n * ret;
}

enum {
	PROGNAME,
	NUMBER,
	NARGS
};

int main(int argc, char *argv[]) {
	if (argc != NARGS) {
		printf("usage: %s number\n", argv[PROGNAME]);
		return -1;
	}

	printf("Fat: %d\n", fatorial(atoi(argv[NUMBER])));

	return 0;
}
