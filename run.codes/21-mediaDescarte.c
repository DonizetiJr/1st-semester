#include <stdio.h>

int main(int argc, char *argv[]) {

	int i;
	float valor[4], min, media;
	scanf("%f%f%f%f", &valor[0], &valor[1], &valor[2], &valor[3]);

	min = valor[0];
	for(i=1;i<4;i++) {
		if(valor[i] < min)
			min = valor[i];
	}

	media = (valor[0]+valor[1]+valor[2]+valor[3]-min)/3;

	printf("%.4f", media);

	return 0;
}