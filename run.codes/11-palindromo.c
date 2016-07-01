#include <stdlib.h>
#include <stdio.h>
#include <string.h>


char string[10001], contrario[10001];


int main(int argc, char *argv[]) {

	int counter = 0, i, j, erro = 0, letras;
	char *string=NULL, c;

	do {
		scanf("%c", &c);
	
		string = (char *)realloc(string, sizeof(char)*(counter+1));
		string[counter++] = c;
	} while(c != 10);
	counter--;


	for(i=0; i < counter; i++) {
		j= counter-1-i;
		if(string[i] != string[j]) 
			erro = 1;
	}

	if(erro == 1) {
		printf("NAO");
	}
	else {
		printf("SIM");
	}

	return 0;
}