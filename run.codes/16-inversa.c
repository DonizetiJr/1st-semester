#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {

	int n, i, *numbers;
	scanf("%d", &n);

	numbers = malloc(sizeof(int)*n);
	for(i = 0; i < n; i++) 
		scanf("%d", &numbers[i]);

	for(i = n - 1; i >= 0; i--) 
		printf("%d\n", numbers[i]);

	free(numbers);

	return 0;
}