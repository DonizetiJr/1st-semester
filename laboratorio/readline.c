#include <stdlib.h>
#include <stdio.h>

char *readW(FILE *stream, char del, char end) {
	char c, counter = 0;
	char *str = NULL;

	do {
		c = fgetc(stream);

		str = (char *)realloc(str, sizeof(char) * (counter+1));
		str[counter++] = c;
	} while (c != '\n' && c != EOF && c != del && c != end);

	str[counter-1] = '\0';

	return str;

}

int main(int argc, char *argv[]) {

	FILE *fp1, *fp2;
	char *str;
	int i;

	fp1 = fopen("test1.in", "r");

	str = readW(fp1, '\n', '\n');
	printf("%s\n", str);
	free(str);

	str = readW(fp1, '\n', '\n');
	printf("%s\n", str);
	free(str);
	
	for(i = 0; i < 3; i++) {
		str = readW(fp1, ',', '\n');
		printf("%s ", str);
		free(str);
	}
	printf("\n");

	for(i = 0; i < 3; i++) {
		str = readW(fp1, ' ', '\n');
		printf("%s ", str);
		free(str);
	}
	printf("\n");

	for(i = 0; i < 3; i++) {
		str = readW(fp1, '-', '\n');
		printf("%s ", str);
		free(str);
	}
	printf("\n");

	
	fp2 = fopen("teste2.in", "r");
	
	str = readW(fp2, '\n', ';');
	printf("%s\n", str);
	free(str);

	str = readW(fp2, '\n', ';');
	printf("%s\n", str);
	free(str);
	
	for(i = 0; i < 3; i++) {
		str = readW(fp2, ',', ';');
		printf("%s ", str);
		free(str);
	}
	printf("\n");

	for(i = 0; i < 3; i++) {
		str = readW(fp2, ' ', ';');
		printf("%s ", str);
		free(str);
	}
	printf("\n");

	for(i = 0; i < 3; i++) {
		str = readW(fp2, '-', ';');
		printf("%s ", str);
		free(str);
	}
	printf("\n");



	fclose(fp1);
	fclose(fp2);

	return 0;
}