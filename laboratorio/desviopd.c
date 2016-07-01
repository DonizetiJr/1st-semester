#include <stdlib.h>
#include <stdio.h>
#include <math.h>


double *recebeNum(int n) {
	int i;
	double *num;

	num = (double *)malloc(sizeof(double)*n);

	for (int i = 0; i < n; i++) {
		scanf("%lf", &num[i]);
	}
return num;
}

int main( int argc, char *argv[ ] ) {

	int n, i;
	double *num, valor, media, variancia, desviopadrao;

	scanf("%d", &n);
	num = recebeNum(n);

	for(i=0; i<n;i++) 
		media += (num[i]/n);

	for (i=0; i < n; i++) 
		variancia += pow((num[i]-media),2)/n;

	desviopadrao = sqrt(variancia);
	printf("%.4lf\n%.4lf", media, desviopadrao);

	free(num);

return 0;
}