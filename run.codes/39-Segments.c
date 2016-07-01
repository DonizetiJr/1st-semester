#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int size(int n) {
	int counter;
	int size;

	size = n/10;
	counter = 1;

	while(size != 0) {
		size = size/10;
		counter++;
	}
	return counter;
}

int check(int num1, int num2, int size1, int size2) {
	int i, j, temp, len;
	int *n1, *n2;

	n1 = (int *)malloc(sizeof(int)*size1);
	n2 = (int *)malloc(sizeof(int)*size2);

	for(i=0; i< size1; i++) {
		temp = num1/pow(10,size1-i-1);
		temp %= 10;
		n1[i] = temp;
	}
	for(i=0; i< size2; i++) {
		temp = num2/pow(10,size2-i-1);
		temp %= 10;
		n2[i] = temp;
	}

	len = size2 - size1;
	for (i = 0; i <= len; i++) {
		for (j = 0; j < size1 && n1[j]==n2[i+j];j++);
		if (j == size1) return 1;
	}

	free(n1);
	free(n2);
	return 0;
}

int main(int agrc, char *argv[]) {

	int smaller, bigger, size1, size2, aux;
	scanf("%d %d", &smaller, &bigger);

	if(smaller > bigger) {
		aux = smaller;
		smaller = bigger;
		bigger = aux;
	}

	size1 = size(smaller);
	size2 = size(bigger);
	if(check(smaller, bigger, size1, size2) == 1)
		printf("%d %d SIM\n", smaller, bigger);
	else
		printf("%d %d NAO\n", smaller, bigger);


	return 0;
}