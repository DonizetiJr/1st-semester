#include <stdlib.h>
#include <stdio.h>

#define ENTER 10

char *readLine() {
	char c; 
	char *string = NULL; 
	int counter = 0; 
	do {
		scanf("%c", &c);
		string=(char *)realloc(string,sizeof(char)*(counter+1));

		string[counter++] = c;
	} while (c != ENTER); 
	string[counter-1] = '\0';
	return string;
}

int max (int a, int b) {
	if(a > b) printf("%d\n", a);
	else printf("%d\n", b);
}

int direcao1 (int **m, int n, int i) {
	int soma, j;

	soma = m[i][i];
	for(j=0; j < i; j++)
		soma += m[i][j] + m[j][i];
	return soma;
} 

int maiorSoma(int *soma, int n) {
	int i, aux, maior;
	maior = 0;
	
	for(i=0; i < n; i++)
		if(soma[i] > maior) maior = soma[i];
	return maior;
}

int soma1 (int **m, int n) {
	int i, j, maior;
	int *soma;
	soma = (int *)calloc(n, sizeof(int));

	for(i=0; i<n; i++)
		soma[i] = direcao1(m, n, i);
	maior = maiorSoma(soma, n);
	free(soma);
	
	return maior;
}

int direcao2 (int **m, int n, int i) {
	int soma, j;

	soma = m[i][i];
	for(j=n-1; j > i; j--)
		soma += m[i][j] + m[j][i];
	return soma;
}   

int soma2 (int **m, int n) {
	int i, j, maior;
	int *soma;
	soma = (int *)calloc(n, sizeof(int));

	for(i=n-1; i >= 0; i--) 
		soma[i] = direcao2(m, n, i);
	maior = maiorSoma(soma, n);
	free(soma);


	return maior;
}

void liberaMatriz (int **m, int n){
	int i;
	for(i=0; i < n; i++)
		free(m[i]);
	free(m);
}   

int **leMatriz (char* nome, int *n) {
	int i, j;
	int **m;

	FILE *fp = fopen(nome, "r");
	fscanf(fp,"%d", n);

	m = (int **)calloc(*n, sizeof(int *));
	for(i=0; i < *n; i++){
		m[i] = (int *)calloc(*n, sizeof(int));
		for(j=0; j < *n; j++){
			fscanf(fp,"%d", &m[i][j]);
		}
	}
	return m;
} 

int main(int argc, char *argv[]) {

	int dimensao, primeira, segunda;
	int *n;
	int **m;
	char *nome;
	nome = readLine();

	m = leMatriz(nome, n);
	primeira = soma1(m, *n);
	segunda = soma2(m, *n);

	max(primeira, segunda);
	liberaMatriz(m, *n);

	free(nome);

	return 0;
}