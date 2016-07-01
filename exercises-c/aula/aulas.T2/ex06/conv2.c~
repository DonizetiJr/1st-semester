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
	int *result = NULL; // NULL??? -> 0
	int counter = 0;

	printf("Digite um número decimal: "); 
	scanf("%d", &n); 

	while (n >= 2) { 	
		q = n / 2; 	
		r = n - (2*q); 	

		// result[i] = r;
		result = (int*)realloc(result, sizeof(int)*(counter+1));
		result[counter++] = r;

		n = q;		
	}
	// result[i] = n;
	result = (int*)realloc(result, sizeof(int)*(counter+1));
	result[counter++] = q;

	while (--counter >= 0) {
		printf("%d", result[counter]);
	}

	free(result);

	return 0;
}
