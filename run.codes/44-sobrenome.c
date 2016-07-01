#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define ENTER 10
#define SPACE 32

char **readName(int *i) {
	int counter;
	char c;
	char **string = NULL;
  
  	string = (char **)realloc(string,sizeof(char *)*((*i)+1));
  	counter = 0;
	do {		
		c = fgetc(stdin); 
		if(c != SPACE){
			string[*i] = (char *)realloc(string[*i], sizeof(char)*(counter+1));
			string[*i][counter++] = c;

		} else {
			string[*i][counter] = '\0';
			(*i)++;
			counter = 0;
			string = (char **)realloc(string,sizeof(char *)*((*i)+1));
		}
	} while (c != ENTER);
	string[*i][counter] = '\0';

	return string;
}

void convert_upper(char *name) {
	int i;
	for(i=0; i< strlen(name)-1; i++) {
		name[i] = toupper(name[i]);
	}
	return;
}

void print(char **name, int n) {
	int i;

	for(i=0; i< strlen(name[n])-1; i++)
		printf("%c", name[n][i]);
	printf(",");

	for(i=0; i < n; i++)
		printf(" %s", name[i]);
	return;
}

int main(int argc, char *argv[]) {
	int count, i;
	char **name;
	count = 0;
	
	name = readName(&count);
	convert_upper(name[count]);
	print(name, count);

	for(i=0;i <= count; i++) free(name[i]);
	free(name);

	return 0;
}