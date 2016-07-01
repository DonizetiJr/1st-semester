#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]){

	int n, i, soma, *digito;
	scanf("%d", &n);

	digito = (int *)malloc(sizeof(int)*n);

	soma = 0;

	for(i = 0; n > 0; i++) {
		digito[i] = n%10;
		soma += digito[i];
		n /= 10;
	}

	printf("%d", soma);

	free(digito);

	return 0;
}