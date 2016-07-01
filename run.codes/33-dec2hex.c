#include <stdlib.h> 	
#include <stdio.h> 	

void dec2hex(long int n) {
	long int q, r, i;
	int *result = NULL;
	int counter = 0;

	q = n;
	while (q != 0) {
		r = q%16;

		//inteiro => char
		if(r<10) r += 48;
		else r += 55;
		result=(int *)realloc(result, sizeof(int)*(counter+1));
		result[counter++] = r;
		q /= 16;
	}

	while (--counter >= 0) {
		if(result[counter] > 10)
			printf("%c", result[counter]);
		else
			printf("%d", result[counter]);

	}

	free(result);
}

int main(int argc, char *argv[]) {
	long int n;
	scanf("%ld", &n);

	dec2hex(n);

	return 0;
}