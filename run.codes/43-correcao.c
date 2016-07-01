#include <stdlib.h>
#include <stdio.h>

char *recebeResp(int n) {
	int i;
	char *respostas;
	respostas = (char *)malloc(sizeof(char)*n);

	for(i=0;i<n;i++) 
		scanf("%c", &respostas[i]);
	return respostas;
}

void estaCerto(int n, char *gabarito, char *respostas) {
	int i;
	double counter = 0;

	for(i=0;i<n;i++) 
		if(gabarito[i] == respostas[i]) counter++;
	printf("%.2lf\n", counter*(10.0/n));
}

int main(int argc, char *argv[]) {

	int questoes, alunos, i;
	char *gabarito, **respostas;
	scanf("%d %d\n", &questoes, &alunos);

	gabarito = recebeResp(questoes);
	respostas = (char **)malloc(sizeof(char *)*alunos);

	for(i=0;i<alunos;i++) {
		respostas[i] = (char *)malloc(sizeof(char)*questoes);
		scanf("%*c");
		respostas[i] = recebeResp(questoes);
	}

	for(i=0;i<alunos;i++) 
		estaCerto(questoes, gabarito, respostas[i]);


	for(i=0;i<alunos;i++) free(respostas[i]);
	free(respostas);
	free(gabarito);

	return 0;
}