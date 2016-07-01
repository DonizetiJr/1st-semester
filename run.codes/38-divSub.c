#include <stdio.h>

int main(int argc, char *argv[]) {

	int a, b, i, resto = 0;
	scanf("%d%d", &a, &b);

	for(i=0; a >= b; i++) {
		resto = a - b;
		a = resto;
	}

	printf("%d\n%d", i, resto);

	return 0;
}