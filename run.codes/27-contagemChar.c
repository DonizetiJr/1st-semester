#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h> // PARA AS FUNÇÕES ISALPHA & ISDIGIT!

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

int main(int argc, char *argv[]) {

	char *text;
	int counterChar=0, counterInt=0, i;

	text = readLine();

	for(i=0;i<strlen(text);i++) {
		
		if(isdigit(text[i]) != 0) counterInt++;
		if(isalpha(text[i]) != 0) counterChar++;

	}

	printf("%d\n", counterChar);
	printf("%d\n", counterInt);


	free(text);

	return 0;
}