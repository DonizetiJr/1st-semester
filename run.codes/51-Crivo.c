#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void crivo (int n, int *lista, int k) {
	int k1, j;
	k1 = floor(sqrt(n));

	printf("%d ", 2);
	for(j=1; j < k; j++) {
		if(lista[j] == n || lista[j]%n != 0 && lista[j] != -1) 
			printf("%d ", lista[j]);
		else lista[j] = -1;	
	}
	printf("\n");
}

void print_crivo(int n, int *lista) {
	int i, k1;
	k1 = floor(sqrt(n));

	crivo(2, lista, n);
	for(i=3; i <= k1; i += 2)
		crivo(i, lista, n);
}

int main(int argc, char *argv[]) {

	int i, k, *lista;
	scanf("%d", &k);

	lista = (int *)malloc(sizeof(int)*k);

	for(i=2; i <= k; i++) {
		lista[i-2] = i;
		printf("%d ", lista[i-2]);
	}
	printf("\n");

	print_crivo(k, lista);

	free(lista);

	return 0;
}