/*
 		-------------
		|           |
 		-------------
		|           |
 		-------------
		|           |
 		-------------
		|           |
 		-------------
	Z	| 01100001  |  HEAP INICIO
 		-------------
		| 01100010  |
 		-------------
		| 00000000  |  HEAP FIM
 		-------------
		|           |
 		-------------
		|           |
 		-------------
		|           |
 		-------------
		|           |
 		-------------
		|           |
 		-------------
		|           |
 		-------------
		|           |   INICIO DA STACK
 		-------------
		|           |
 		-------------
		|           |
 		-------------
		|           |
 		-------------
		|           |
 		-------------
		|           |
 		-------------
		|           |
 		-------------
		|           |
 		-------------
		|           |  readLine: int counter = 0;
		|    3      |
		|           |
		|           |
 		-------------
		|           |  readLine: char *string
		|           |
		|           |
		|    Z      |
		|           |
		|           |
		|           |
		|           |
 		-------------
		| 01100001  |  readLine: char c
 		-------------
		|           |  Endereço de retorno de readLine
		|           |
		|           |
		|           |  COPIAR ESTE ENDERECO DE RETORNO
		|     2     |  PARA O REGISTRADOR EIP
		|           |
		|           |
		|           |
 		-------------
		|           |  MAIN: char *s;
		|           |
		|           |
		|    Z      |
		|           |
		|           |
		|           |
		|           |  FIM DA STACK
 		-------------

 */
#include <stdlib.h>
#include <stdio.h>

char *readLine() {
	char c;
	//char *string = NULL;
	char string[255];
	int counter = 0;

	do {
		// ler caracteres a partir do teclado
		// stdin = standard input => teclado
		c = fgetc(stdin); // file get char
		string=(char *)realloc(string,sizeof(char)*(counter+1));
		string[counter++] = c;
	} while (c != 10);
	string[counter-1] = '\0';

	return string;	// COPIAR O QUE ESTAH DENTRO DA VARIAVEL string
			// PARA DENTRO DO REGISTRADOR EAX
}

int main(int argc, char *argv[]) {
	char *s;

	s = readLine();		// 1
	printf("%s\n", s);	// 2
	free(s);

	return 0;
}







