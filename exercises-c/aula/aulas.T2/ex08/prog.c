/*
Problema: Dadas duas strings text e word, procure word em text.

Exemplo:

	text = "ttetesteabc"
	word = "teste"

Algoritmo: Conjunto de passos (em certa ordem) para resolver meu
	   problema.

Solução
=======

1) i = 0
2) A partir de text[i]
	3) n = 0
	4) if word[n] == text[i+n]
		- Incrementar n
		- Voltar para o passo 4
	   else
		- Voltar para o passo 2, incrementar i
*/

#include <stdlib.h> // malloc, calloc, realloc, free
#include <stdio.h>  // printf, scanf
#include <string.h> // strlen

#define ENTER 10

#define TRUE 1
#define FALSE 0

char *readLine() {
	char c; // 1 byte (STACK)
	char *string = NULL; // 8 bytes (STACK)
	int counter = 0; // 4 bytes (STACK)
	
	do {
		c = fgetc(stdin);
		// HEAP (realloc, calloc, malloc)
		string=(char *)realloc(string,sizeof(char)*(counter+1));
		string[counter++] = c;
	} while (c != ENTER);
	string[counter-1] = '\0';

	// desenhar stack e heap
	
	return string;
}

int *locate(char *text, char *word) {
	// text = "abc teste abc teste abc teste"
	// word = "teste"
	// retorno = 4, 14, 24
	int i, n, counter = 0;
	int *location = NULL;

	for (i = 0; i <= strlen(text)-strlen(word); i++) {
		for (n = 0; n < strlen(word) &&
			    word[n] == text[i+n]; n++);
		if (n == strlen(word)) {
			// guardar o i em algum lugar!
			location = (int *) realloc(location,
					sizeof(int) * (counter+1));
			location[counter++] = i;
		}
	}

	location = (int *) realloc(location, sizeof(int) * (counter+1));
	location[counter++] = -1;

	// desenhar stack e heap

	return location;
}

void print_locations(int *l) {
	int i = 0;

	// desenhar stack e heap
	while (l[i] != -1) {
		printf("Location %d: %d\n", i, l[i]);
		i++;
	}
}

int contains(char *text, char *word) {
	int i, n;

	//	         i
	//	         |
	// text = "ttetesteabc"  -> 11			11-5=6
	// word =       "teste"  -> 5
	for (i = 0; i <= strlen(text)-strlen(word); i++) {
		for (n = 0; n < strlen(word) &&
			    word[n] == text[i+n]; n++);
		if (n == strlen(word)) return TRUE;
	}

	return FALSE;

	/*
	1) i = 0
	2) A partir de text[i]
		3) n = 0
		4) if word[n] == text[i+n]
			- Incrementar n
			- Voltar para o passo 4
		   else
			- Voltar para o passo 2, incrementar i
	 */
}

int main(int argc, char *argv[]) {
	char *text; // 8 bytes (STACK)
	char *word; // 8 bytes (STACK)
	int *loc; // 8 bytes (STACK)

	// desenhar
	printf("Digite text: ");
	text = readLine();
	printf("Digite word: ");
	word = readLine();

	/*
	//if (contains(text, word) == TRUE) {
	if (contains(text, word)) {
		printf("Contém...\n");
	} else {
		printf("Não contém...\n");
	}*/

	loc = locate(text, word);
	print_locations(loc);

	free(text);
	free(word);
	free(loc);

	return 0;
}










