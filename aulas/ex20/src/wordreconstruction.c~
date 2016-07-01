#include <stdlib.h>
#include <stdio.h>
#include <stdio_ext.h>
#include <file.h>
#include <utils.h>
#include <bam.h>
#include <matrix.h>
#include <preprocessing.h>
#include <string.h>

enum {
	PROGNAME,
	FILENAME,
	NARGS
};

char *readLine(int maxlength) {
	char *str = (char *) malloc(sizeof(char) * (maxlength + 1));
	int i;
	// str (char *)
	//   |
	//   -----> "a"
	//          "a"
	//          "a"
	//          "\0"   maxlength = 3

	for (i = 0; i < maxlength && (str[i] = fgetc(stdin)) != ENTER; i++);
	for (; i < maxlength; i++) str[i] = ' ';
	str[i] = '\0';

	__fpurge(stdin);

	return str;
}

int main(int argc, char *argv[]) {
	byte *stream;
	long n;
	char *strings, *queryString, *string;
	char **allwords, **uniquewords;
	int i, nwords, maxlength, newwords;
	double **allvectors, **A, **query;

	if (argc != NARGS) {
		printf("usage: %s filename\n", argv[PROGNAME]);
		return -1;
	}

	printf("READING INPUT FILE...\n");
	stream = readFullFile(argv[FILENAME], &n);

	printf("PREPROCESSING...\n");
	strings = preprocessing(stream, n);
	printf("preprocessed: %s\n\n", strings);

	printf("EXTRACTING WORDS...\n");
	allwords = words(strings, &nwords);
	for (i = 0; i < nwords; i++) {
		printf("%s\n", allwords[i]);
	}

	printf("NORMALIZING WORDS...\n");
	maxlength = normalize(allwords, nwords);

	printf("EXTRACTING UNIQUE WORDS...\n");
	uniquewords = unique(allwords, nwords, &newwords);

	printf("PREPARING THE VECTORS {+1,-1}...\n");
	allvectors = vectors(uniquewords, newwords, maxlength);

	printf("GENERATING MATRIX A...\n");
	A = bam_training(allvectors, newwords, maxlength*BITS_IN_BYTE);

	query = (double **) malloc(sizeof(double *));
	// query (double **)
	//    |
	//    ----> double *

	while (1) {
		printf("Type a word: ");
		queryString = readLine(maxlength);
		printf("Word: %s\n", queryString);

		if (strcmp(queryString, "q") == 0) {
			free(queryString);
			break;
		}

		query[FIRST_ROW] = char2vec(queryString, maxlength);
		string = bam_testing(A, maxlength*BITS_IN_BYTE, maxlength*BITS_IN_BYTE, query);
		printf("Did you mean '%s'?\n", string);
		free(query[FIRST_ROW]);
		free(queryString);
		free(string);
	}

	free(query);
	free(stream);
	free(strings);
	for (i = 0; i < nwords; i++) free(allwords[i]); free(allwords);
	for (i = 0; i < newwords; i++) free(uniquewords[i]); free(uniquewords);
	matrix_free(allvectors, newwords);
	matrix_free(A, maxlength * BITS_IN_BYTE);

	return 0;
}













