#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ENTER 10
#define TRUE  1
#define FALSE 0
	

int main(int argc, char *argv[]) {

	int i, quantidade, *vector, *indice, counter;
	char nome[100];
	scanf("%s", nome);

	FILE *fp = fopen(nome, "r");
	fscanf(fp,"%d", &quantidade);

	vector = (int *)malloc(sizeof(int)*quantidade);
	indice = (int *)malloc(sizeof(int)*quantidade);


	i=0;
	for(i=0;i<quantidade;i++) {
		fscanf(fp, "%d", &vector[i]);
	}

	for(i=0; i<quantidade; i++) indice[i] = i;
	

	for(counter=0; counter < quantidade-1; counter++) {
		for(i=1; i < quantidade-counter; i++){
				if(vector[indice[i]] < vector[indice[i-1]]){
					int aux = indice[i-1];
					indice[i-1] = indice[i];
					indice[i] = aux;
				}
		}
	}

	for(i=0; i<quantidade;i++)
		printf("%d ", indice[i]);
	printf("\n");
	
	

	free(vector);


	return 0;
}