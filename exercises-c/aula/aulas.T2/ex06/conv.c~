#include <stdlib.h>
#include <stdio.h>

/*
 	STACK					HEAP
	=====					====

   	i -> 4 bytes				
   	result -> 8 bytes
   	q -> 4 bytes
   	r -> 4 bytes
   	n -> 4 bytes
 */

int main(int argc, char *argv[]) {

	int n, r, q;
	int *result;
	int i;

	result = (int *) calloc(5, sizeof(int));

	printf("Digite um número decimal: "); 
	scanf("%d", &n); 

	i = 0;
	while (n >= 2) { 	
		q = n / 2; 	
		r = n - (2*q); 	
		result[i] = r;
		i++; // i = i + 1;
		n = q;		
	}
	result[i] = n;

	for (i = 4; i >= 0; i--) {
		printf("%d", result[i]);
	}

	free(result);

	return 0;
}
