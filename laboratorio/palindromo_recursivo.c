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

int palindromo(char *string, int len, int i) {
	//Se o i for maior ou igual à metade do tamanho da string
	//retorna 1, ou seja, todas as letras foram comparadas e 
	//confirmadas como iguais
	if(i >= len/2) return 1;

	if(string[i] != string[len-1-i]) return 0; //Não palíndromo
	else return palindromo(string, len, ++i);//Letras são iguais e chama
											//a função para comparar com a seguinte
}

int main(int argc, char *argv[]) {
		int len;
		char *string;

		string = readLine(); //recebe a palavra
		//Se o retorno da função for 1 é palíndromo.

		len = strlen(string);

		if(palindromo(string, len, 0)) printf("Palindromo\n");
		//Caso contrário, não é.
		else printf("Nao-Palindromo\n");

		free(string);

	return 0;
}