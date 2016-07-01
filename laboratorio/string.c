#include <stdio.h>

int main() {

	int n;
	scanf("%d", &n);

	int idade[n];
	double altura[n];
	char nome[n][11];

	int i;
	for(i = 0; i < n; i++) {
		scanf("%s %d %lf", nome[i], &idade[i], &altura[i]);
		printf("%s\n", nome[i]);
	}

	return 0;
}