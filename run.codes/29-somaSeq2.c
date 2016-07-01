#include <stdio.h>

int main(int argc, char *argv[]) {

	int n, i; 
	double soma=0;
	scanf("%d", &n);


	for(i=1; i<=n; i++) {
		if(i%2 != 0) soma += (double)1/i;
		else soma -= (double)1/i;
	}

	printf("%.4lf", soma);


	return 0;
}