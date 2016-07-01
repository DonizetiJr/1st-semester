#include <stdlib.h>
#include <stdio.h>
#include <math.h>


int main( int argc, char *argv[ ] ) {

	int n;
	scanf("%d", &n);
	int valor[n];
	double soma = 0, media, variancia, desviopadrao;

	for (int i = 0; i < n; i++) {
		scanf("%d", &valor[i]);
		soma += valor[i];
	}

	media = soma / n;
	printf("Media: %lf\n", media);

	for (int j; j < n; j++) {
		valor[j] -= media;
		valor[j] *= valor[j];
		variancia += valor[j];
	}

	variancia /= (n);

	desviopadrao = sqrt(variancia);
	printf("Desvio Padrao: %lf", desviopadrao);

return 0;
}