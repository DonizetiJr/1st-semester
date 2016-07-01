#include <stdio.h>

int main(int argc, char *argv[]) {

	int n, i; 
	double soma=0, denominador;
	scanf("%d", &n);

	denominador = 1.0;
	for(i=0; i<n; i++){
			soma += (double)(denominador/(n-i));
			denominador += 2; 
	}

	printf("%.4lf", soma);


	return 0;
}