#include <stdlib.h>
#include <stdio.h>

#define MEDALHAS 3
#define ENTER 10

	
void readLine(char *countries) {
	int i;
 
	for (i = 0; i < MEDALHAS; i++) {
		scanf("%c", &countries[i]);
		printf("%p\n", &countries[i]);
		printf("%c\n", countries[i]);
	}
	countries[MEDALHAS] = '\0';
	printf("%p\n", &countries[MEDALHAS]);
}

void freePointers(int **m, char **m2, int n) {
	int i;

	for(i = 0; i < n; i++) {
		free(m[i]);
		free(m2[i]);
	}
	free(m);
	free(m2);
}

int main(int argc, char *argv[]) {
	int n, i;
	int **awards;
	char **countries;
	scanf("%d", &n);

	countries = (char **)calloc(n,sizeof(char *));
	for(i = 0; i < n; i++) 
		countries[i] = (char *)realloc(countries[i],sizeof(char)*(MEDALHAS+1));
	
	awards = (int **)calloc(n,sizeof(int *));	
	for(i = 0; i < n; i++) 
		awards[i] = (int *)realloc(awards[i],sizeof(int)*MEDALHAS);

	for(i = 0; i < n; i++) {
		readLine(countries[i]);
		scanf("%d %d %d", &awards[i][0], &awards[i][1], &awards[i][2]);
	}

	for(i = 0; i < n; i++) {
		printf("%s\n", countries[i]);
		printf("%d %d %d", awards[i][0], awards[i][1], awards[i][2]);
	}

	freePointers(awards, countries, n);

	return 0;
}