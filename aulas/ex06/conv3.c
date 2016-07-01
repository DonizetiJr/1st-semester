#include <stdlib.h>
#include <stdio.h>

void dec2bin(int n) {
	int r, q;
	int *result = NULL; // NULL??? -> 0
	int counter = 0;

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
	printf("\n");

	free(result);
}

int main(int argc, char *argv[]) {
	int n;

	printf("Digite um número decimal: "); 
	scanf("%d", &n); 

	dec2bin(n);

	printf("%d", n);

	return 0;
}
