#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main( int argc, char *argv[ ] ) {

	int n;
	scanf("%d", &n);

	int idade[n];
	double altura[n];
	char nome[n][11];
	char age_ord[11];
	char height_name[n][11];
	char height_ord[11];

	int i;
	for(i = 0; i < n; i++) {
		scanf("%s %d %lf", nome[i], &idade[i], &altura[i]);
		strcpy(height_name[i], nome[i]);
	}
	int counter;
		for(counter=0; counter < n-1; counter++) {
			for(i=1; i < n-counter; i++){
					if(idade[i] < idade[i-1]) {
						
						int aux = idade[i-1];
						idade[i-1] = idade[i];
						idade[i] = aux;

						strcpy(age_ord,nome[i-1]);
						strcpy(nome[i-1], nome[i]); 
						strcpy(nome[i],age_ord);
					}
			}
		}
	printf("Por idade: %s", nome[0]);
	for(i=1; i < n; i++)
		printf(", %s", nome[i]);

	for(counter=0; counter < n-1; counter++) {
		for(i=1; i < n-counter; i++){
			if(altura[i] < altura[i-1]) {
						
				double aux = altura[i-1];
				altura[i-1] = altura[i];
				altura[i] = aux;

				strcpy(height_ord,height_name[i-1]);
				strcpy(height_name[i-1], height_name[i]); 
				strcpy(height_name[i],height_ord);
			}
		}
	}		
	printf("\nPor altura: %s", height_name[0]);
	for(i=1; i < n; i++)
		printf(", %s", height_name[i]);


return 0;
}