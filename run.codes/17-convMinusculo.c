#include <stdlib.h>
#include <stdio.h>


#define ENTER 10

char *readLine() {
	char c;
	char *string = NULL;
	int counter = 0;

	do {
		c = fgetc(stdin);

		string=(char *)realloc(string, sizeof(char)*(counter+1));
		string[counter++] = c+32;
	} while (c != ENTER);
	string[counter-1] = '\0';

	return string;
}


int main(int argc, char *argv[]) {

	char *text;
	text = readLine();

	printf("%s\n", text);

	free(text);



	return 0;
}