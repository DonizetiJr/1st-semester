#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ENTER 10

	//Recebe os caracteres digitados e retorna uma vetor que 
   //aponta para a heap.
	char *readLine() {
	char c; 
	char *string = NULL; 
	int counter = 0; 

	do {
		c = fgetc(stdin);
		
		string=(char *)realloc(string,sizeof(char)*(counter+1));
		string[counter++] = c;
	} while (c != ENTER); //recebe do teclado até o Enter.
	string[counter-1] = '\0';
	
	return string;
}

int palindromo(char *string) {
	int i, len;
	len = strlen(string); //Total de caracteres
	for(i =0; i < len/2; i++) {
		//Se a letra lida pela esquerda for igual a sua respectiva
		//quando lida pela direita retorna 0.
		if(string[i] != string[len-1-i]) return 0; //Não palíndromo
	}
	return 1; // É palíndromo
}

int main(int argc, char *argv[]) {
		char *string;

		string = readLine(); //recebe a palavra
		//Se o retorno da função for 1 é palíndromo.
		if(palindromo(string)) printf("Palindromo\n");
		//Caso contrário, não é.
		else printf("Nao-Palindromo\n");

		free(string);

	return 0;
}