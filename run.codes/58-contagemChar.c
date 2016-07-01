#include <stdlib.h>
#include <stdio.h>

#define ENTER 10

	char *readLine() {
	char c; 
	char *string = NULL; 
	int counter = 0; 

	do {
		c = fgetc(stdin);
		
		string=(char *)realloc(string,sizeof(char)*(counter+1));
		string[counter++] = c;
	} while (c != ENTER); 
	string[counter-1] = '\0';
	
	return string;
}

void size(FILE *fp_input) {
	int tamanho;

	fseek(fp_input, 0, SEEK_END); 
	tamanho = ftell(fp_input); 
	fseek(fp_input, 0, SEEK_SET); 
	
	printf("%d", tamanho);

	return;
}


int main(int argc, char *argv[]) {
	FILE *fp;
	int tamanho;
	char *nome;

	nome = readLine(); //recebe o nome do arquivo
	fp = fopen(nome, "r");

	size(fp);

	fclose(fp);
	free(nome);

	return 0;
}