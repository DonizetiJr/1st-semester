#include <stdlib.h>
#include <stdio.h>

int sum_pa(int n) {
	int ret;

	// caso base
	if (n < 1) return 0;

	// passo recursivo
	ret = sum_pa(n-1);

	return n + ret;
}

/*
 	sum_pa(1-1) | n = 0    	return 0
 	sum_pa(2-1) | n = 1	n + sum_pa(0) = 1 + 0 = 1;	return 1
 	sum_pa(3-1) | n = 2	n + sum_pa(1) = 2 + 1 = 3;	return 3
 	sum_pa(4-1) | n = 3	n + sum_pa(2) = 3 + 3 = 6;	return 6
 	sum_pa(5-1) | n = 4	n + sum_pa(3) = 4 + 6 = 10;	return 10
 	sum_pa(5)   | n = 5	n + sum_pa(4) = 5 + 10 = 15;	return 15
 */

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

	int number = atoi(argv[NUMBER]);
	printf("Sum PA: %d\n", sum_pa(number));

	return 0;
}









