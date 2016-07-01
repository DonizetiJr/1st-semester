#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {

	int n,i;
	float *nota, quociente=0, media;

	scanf("%d", &n);
	nota = malloc(sizeof(float)*n);
	
	for(i=0; i<n; i++) {
		scanf("%f", &nota[i]);

		quociente += 1/(nota[i]+1);
	}

	media = n/quociente-1;
	printf("%.2f", media); 

	free(nota);

	return 0;
}