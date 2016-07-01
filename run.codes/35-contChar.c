#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ENTER 10

char *leString() {
	int counter = 0;
	char *string = NULL;
	char c;

	do {
		scanf("%c", &c);
		string = (char *)realloc(string, sizeof(char)*(counter+1));
		string[counter++] = c;

	}while (c != ENTER);
	string[counter] = '\0';

return string;
}

int contaChar(char *string, char key) {
	int i;
	int counter = 0;

	for(i=0;i<strlen(string);i++) {
		if(string[i] == key) counter++;
	}
return counter;
}

int main(int argc, char *argv[]) {

	int counter;
	char key;
	char *string;
	string = leString();

	scanf("%c", &key);
	counter = contaChar(string, key);

	printf("%d", counter);

	free(string);

	return 0;
}