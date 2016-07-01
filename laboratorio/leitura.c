#include <stdlib.h>
#include <stdio.h>

#define ENTER 10

char *readString(FILE *stream, char end) {

	int c, counter = 0;
	char *str = NULL;

		do {
		c = fgetc(stdin);

		str=(char *)realloc(str,sizeof(char)*(counter+1));
		str[counter++] = c;
	} while (c != ENTER);

	str[counter-1] = '\0';

	if(c == EOF){
		ungetc(c,stream);
	}

	return str;
}

char *nextWord(FILE *stream, char sep, char end) {

	int c, counter = 0;
	char *str = NULL;

	do {
		c = fgetc(stream);

		str = (char *)realloc(str, sizeof(char) * (counter+1));
		str[counter++] = c;
	} while (c != '\n' && c != EOF && c != sep && c != end);

	str[counter-1] = '\0';

	if(c == EOF || c == end){
		ungetc(c,stream);
	}

	return str;
}

char *nextWordIgnore(FILE *stream, char sep, char end, char ignore) {

	int c, counter = 0;
	char *str = NULL;

	do {
		c = fgetc(stream);
		if(c == ignore) continue;

		str = (char *)realloc(str, sizeof(char) * (counter+1));
		str[counter++] = c;
	} while (c != '\n' && c != EOF && c != sep && c != end);


	str[counter-1] = '\0';

	if(c == EOF ||  c == end){
		ungetc(c,stream);
	}

	return str;
}

int hasNextWord(FILE *stream, char token) {

	int c,
	returnValue = 1;

	if(stream != NULL) {

		c = fgetc(stream);

		if(c == token){
			returnValue = 0;
	}else{
		if (c == EOF)
			returnValue = 0;
		ungetc(c, stream);
		}
	}
	return returnValue;
}

int isNotEOF(FILE *stream) {

	int c,
		returnValue = 1;

	if(stream != NULL) {
		c = fgetc(stream);
		if(c == EOF)
			returnValue = 0;

		ungetc(c, stream);
	}

	return returnValue;
}


int main(int argc, char *argv[]) {

	FILE *fp = stdin;
	FILE *fp2;
	char *name, *word, *str;
	int sum, i;
	float sumf;

	word = readString(fp, '\n');
	int exercicio = atoi(word);

	switch (exercicio){

		//================================================================
		case 1:
			str = readString(fp, '\n');
			printf("%s\n", str);
			free(str);

			while(isNotEOF(fp)) {
				while(hasNextWord(fp, '\n')){
					word = nextWord(fp, ' ', '\n');
					printf("%s ", str);
					free(str);
				}
				printf("\n");
			}
			break;

		//================================================================
		case 2:
			name = readString(fp, '\n');
			fp2 = fopen(name, "r");
			free(name);

			str = nextWord(fp2, '\n', '\n');
			printf("%s", str);
			free(str);

			while(isNotEOF(fp2)) {
				while(hasNextWord(fp2, '\n')){ 
					word = nextWord(fp2, ' ', '\n');
					printf("%s ", word);
					free(word);
				}
				printf("\n");
			}
			fclose(fp2);
			break;

		//================================================================
		case 3:

			while(isNotEOF(fp)) {
				while(hasNextWord(fp, ';')){
					word = nextWord(fp, ',', ';');
					printf("%s ", word);
					free(word);
				}
				printf("\n");
			}
			break;

		//================================================================
		case 4:
			while(isNotEOF(fp)) {
				while(hasNextWord(fp, '\n')){
					word = nextWordIgnore(fp, ',', '\n', ' ');
					printf("%s ", word);
					free(word);
				}
				printf("\n");
			}
			break;

		//================================================================
		case 5:
			for (i = 0; i < 3; i++){
				while(hasNextWord(fp, '\n')){
					word = nextWord(fp, ',', '\n');
					printf("%s\n", word);
					free(word);
				}
			}
			for (i = 0; i < 3; i++){
				while(hasNextWord(fp, '\n')){
					word = nextWordIgnore(fp, ',', '\n', ' ');
					sum = atoi(word);
					printf("%d ", sum*sum);
					free(word);
				}
				printf("\n");
			}
			while(isNotEOF(fp)) {
				sumf = 0;
				while(hasNextWord(fp, '\n')){
					word = nextWordIgnore(fp, ',', '\n', ' ');
					sumf += atof(word);
					free(word);
				}
				printf("%f\n", sumf);
			}
			break;
	}
	fclose(fp);

	return 0;
}
