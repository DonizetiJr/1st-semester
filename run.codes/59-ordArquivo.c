#include <stdlib.h>
#include <stdio.h>

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


int main(int argc, char *argv[]) {
	


	return 0;
}