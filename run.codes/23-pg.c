#include <stdio.h>
#include <math.h>

int main (int argc, char *argv[]) {

	float a,q,n;
	float ultimo, soma;
	scanf("%f %f %f", &a, &q, &n);

	ultimo = a*pow(q,n-1.0);
	printf("%.2f\n", ultimo);

	soma = a*((pow(q,n)-1)/(q-1.0));
	printf("%.2f", soma);


	return 0;
}