#include <stdio.h>

int main (int argc, char *argv[]) {

	//long long int para que imprima valores altos (caso de teste)
	long long int a,r,n, ultimo, soma;
	scanf("%lld %lld %lld", &a, &r, &n);

	ultimo = a+(n-1)*r;
	printf("%lld\n", ultimo);

	soma = ((a+ultimo)*n)/2;
	printf("%lld", soma);


	return 0;
}