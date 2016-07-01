#include <stdlib.h> 	
#include <stdio.h> 	

void dec2bin(int n) {
	int q, r, i;
	int *result = NULL;
	int counter = 0;

	while (n >= 2) {
		q = n / 2;
		r = n - (2*q);
		result=(int *)realloc(result, sizeof(int)*(counter+1));
		result[counter++] = r;
		n = q;
	}

	result=(int *)realloc(result, sizeof(int)*(counter+1));
	result[counter++] = q;

	for(i=0;i<(32-counter);i++) printf("0");
	while (--counter >= 0) {
		printf("%d", result[counter]);
	}

	free(result);
}

int main(int argc, char *argv[]) {
	int n;
	scanf("%d", &n);

	dec2bin(n);

	return 0;
}