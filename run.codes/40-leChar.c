#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ENTER 10

char *leString() {
	int counter = 0;
	char c;
	char *string = NULL;

	do {		
		c = fgetc(stdin); 

		string = (char *)realloc(string, sizeof(char)*(counter+1));
		string[counter++] = c;
	} while (c != ENTER);
	string[counter] = '\0';

	return string;
}

void print(char *string) {
	int i;

	for(i=0; i<strlen(string)-1;i++) //-1 para desconsiderar o \0
		printf("%c\n", string[i]);

return;
}

int main(int argc, char *argv[]) {
	char *string;

	string = leString();
	print(string);

	free(string);

	return 0;
}