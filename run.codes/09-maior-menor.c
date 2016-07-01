#include <stdlib.h>
#include <stdio.h>

int main (int argc, char *argv[]) {

	int n, i, j;
	long long int *conjunto, maior, menor;

	scanf("%d", &n);
	conjunto = malloc(sizeof(long long int)*n);

	for (i = 0; i < n; i++)
		scanf("%lld", &conjunto[i]);

	if (conjunto[0] > conjunto[1]){
		maior = conjunto[0]; 
		menor = conjunto[1]; 
	}
	else {
		maior = conjunto[1];
		menor = conjunto[0]; 
	}

		
	for (j = 2; j < n; j++) {

		if (conjunto[j] > conjunto[j - 1]) {
			if(conjunto[j] > maior) 
				maior = conjunto[j];
			}
			else {
				if (conjunto[j] < menor)
					menor = conjunto[j];
				}
			}
	
	printf("%lld\n", maior - menor);

	return 0;
}