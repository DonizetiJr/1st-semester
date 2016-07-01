#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ENTER 10
#define SPACE 32
#define TRUE  1
#define FALSE 0


int counterSpace;

char *readLine(int counter) {
	char c; 
	char *string = NULL; 
	int count = 0; 

	do {
			c = fgetc(stdin);
			string=(char *)realloc(string,sizeof(char)*(count+1));
			string[count++] = c;
			if(c==SPACE) {
			 counterSpace++;
			}
	} while (c != ENTER);
	string[count-1] = '\0';
	
	return string;
}

int main( int argc, char *argv[ ] ) {

	int i, j;
	char *frase;
	int counter = 0;
	counterSpace = 0;
	frase = readLine(counterSpace);

	// quebra a frase em palavras com limitante sendo o espaço
	// e as aloca na Heap.
	char **palavra=NULL, *token, *temp;
	
	palavra=(char **)realloc(palavra,sizeof(char*));
	palavra[0] = strtok(frase, " ");

	for(i=1;i<=counterSpace;i++) {
		palavra=(char **)realloc(palavra,(1+i)*sizeof(char*));
		palavra[i] = strtok(NULL, " ");
		if(palavra[i] == NULL) break;
	}
	
	// Sort
	for(i=0; i<=counterSpace; i++) {
		for(j=i+1; j<=counterSpace; j++) {
			if(strcmp(palavra[i],palavra[j])>0) {
				char *temp = palavra[i];
				palavra[i] = palavra[j];
				palavra[j] = temp;
			}
		}
	}

	for(i=0;i<=counterSpace;i++){
		if(i==counterSpace){
		 printf("%s\n", palavra[i]);
		} else if(strcmp(palavra[i],palavra[i+1])!=0){
			printf("%s\n", palavra[i]);
		} else {
			while(strcmp(palavra[i],palavra[i+1])==0){
			i++;
			if(i==counterSpace) break;
			}
		}
	}



free(frase);
free(palavra);

	return 0;
}
