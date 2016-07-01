#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {

	int n, i;
	double x, y, calculo, resultado, resultadofinal,
			primeirox, primeiroy;

	scanf("%d", &n);

	resultado = 0;

	scanf ("%lf %lf", &primeirox, &primeiroy);
	
	for (i = 1; i < n; i++) {
		scanf ("%lf %lf", &x, &y);

		calculo = (primeirox - x) * (primeirox - x) +
					 (primeiroy - y) * (primeiroy - y);
		
		resultado += sqrt(calculo);

		primeirox = x;
		primeiroy = y	;
	}
	printf("%.4lf", resultado);



return 0;

}