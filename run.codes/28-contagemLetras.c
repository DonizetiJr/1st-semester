#include <stdlib.h>
#include <stdio.h>


char *readLetter(int n){

	int i;
	char *letter = NULL, c;

	for(i=0; i<n; i++) {
		scanf(" %c", &c);

		letter = (char *)realloc(letter, sizeof(char)*(i+1));
		letter[i] = c;
	}
	return letter;
}

void countChars(char *letter, int n){
	int i, maiusculas=0, minusculas=0;

	for(i=0;i<n;i++) {
		if(letter[i] > 'A' && letter[i]< 'Z' ) maiusculas++;
		if(letter[i]>'a' && letter[i] <'z') minusculas++; 
	}
	printf("%d %d\n", maiusculas, minusculas);
}

int main(int argc, char *argv[]) {

	int n, i;
	char *letra;
	scanf("%d", &n);

	letra = readLetter(n);
	countChars(letra, n);
	

	free(letra);

	return 0;
}