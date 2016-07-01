#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double *receiveNum(int *n) {
	int i;
	double *num = NULL;

	i = 0;
	*n = 1;
	num = (double *)realloc(num, sizeof(double)*(*n));
	while(scanf("%lf", &num[i]) != EOF) {
		i++;
		(*n)++;
		num = (double *)realloc(num, sizeof(double)*(*n));
	}
	return num;
}

double media(double *num, int n, double *medias) {
	double sum, med;

	if(n == 1.0) {
		medias[0] = (num[0]+num[1])/2.0;
		printf("%.2lf ", medias[0]);
		return medias[0];
	
	}else {
		med = media(num, n-1.0, medias);
		medias[n-1] = med+((num[n]-med)/(n+1.0));
		printf("%.2lf ", medias[n-1]);

		return medias[n-1];
	}
}

double variancia(double *num, int n, double *medias) {
	double sum, var;

	if(n == 1.0) {
		sum = pow(num[0]-medias[0],2) + 
				pow(num[1]-medias[0],2);
		printf("%.2lf ", sum);
		return sum;
	
	}else {
		var = variancia(num, n-1, medias);
		sum = ((n-1.0)/n)*var + pow(num[n]-medias[n-2],2)/(n+1);
		printf("%.2lf ", sum);

		return sum;
	}
}

int main(int argc, char *argv[]) {
	int counter;
	double *num, *medias;

	num = receiveNum(&counter);
	medias = (double *)calloc(counter-2,sizeof(double));
	media(num, counter-2, medias);
	printf("\n");
	variancia(num, counter-2, medias);

	free(num);
	free(medias);

	return 0;
}