#include <stdlib.h>
#include <stdio.h>

// 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
//
// t_n / t_{n+1} = proporção áurea

// fibonacci
//
// n==1, n==2	->	return 0+1
// fibonacci(n-2) + fibonacci(n-1)

int fibonacci(int n) {
	int ret1, ret2;
	/*
	if (n == 1) return 0;
	if (n == 2) return 1;
	*/
	if (n > 0 && n < 3) return n-1;

	printf("%d\n", n);
	ret1 = fibonacci(n-2);
	ret2 = fibonacci(n-1);

	return ret1 + ret2;
}

int main(int argc, char *argv[]) {

	printf("Fib: %d\n", fibonacci(atoi(argv[1])));

	return 0;
}
