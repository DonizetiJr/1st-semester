#include <stdio.h>
#include <math.h>

double fatorial(int n) {
	if(n != 0) return n*fatorial(n-1);
	else return 1;
}

int main(int argc, char *argv[]) {
	int i, sinal = -1;
	double angulo, seno, termo;

	scanf("%lf", &angulo);

	seno = 0;
	for(i=1; i < 600; i += 2) {
		termo = (double)pow(angulo,i)/fatorial(i);
		sinal = -sinal;
		seno += (sinal*termo);
	}
	printf("%.6lf", seno);

	return 0;
}