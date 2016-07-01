#include <stdio.h>

int main(int argc, char *argv[]) {

	long long int n, i; 
	double soma = 0;
	scanf("%lld", &n);

	for(i=1; i <= n; i++){
		soma += i/(n-i+1.0); 
	}

	printf("%.4lf", soma);

	return 0;
}