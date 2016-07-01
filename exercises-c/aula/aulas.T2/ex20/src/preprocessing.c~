#include <stdlib.h>
#include <stdio.h>
#include <utils.h>
#include <ctype.h>
#include <string.h>
#include <matrix.h>

char *preprocessing(byte *stream, long n) {
	long i;
	char *preprocessed = NULL;
	int counter = 0;
	char character;
	
	for (i = 0; i < n; i++) {
		// lowercase
		character = (char) tolower(stream[i]);
	
		// a-z, espaços devem ser preservados
		if (isalpha(character) || isspace(character)) {
			preprocessed = (char *) realloc(preprocessed,
					sizeof(char) * (counter+1));
			preprocessed[counter++] = character;
		}
	}

	preprocessed = (char *) realloc(preprocessed, sizeof(char) * (counter+1));
	preprocessed[counter] = '\0';

	return preprocessed;
}

char **words(char *string, int *counter) {
	char *str;
	char **allwords = NULL;

	*counter = 0;

	// allwords (char**)
	//    |
	//    -------->  char* ---> "abababa"
	//    		 char* ---> "dgdg"
	//    		 char*
	//    		 char*
	//    		 char*

	str = strtok(string, " \t\r\f\v\n");

	if (str != NULL) {
		allwords = (char **) realloc(allwords, sizeof(char*) * 
				((*counter)+1));
		allwords[*counter] = (char *) malloc(sizeof(char) *
					(strlen(str)+1));
		strcpy(allwords[(*counter)++], str);
	}

	while (str != NULL) {
		str = strtok(NULL, " \t\r\f\v\n");

		if (str != NULL) {
			allwords = (char **) realloc(allwords, 
					sizeof(char*) * ((*counter)+1));
			allwords[*counter] = (char *) malloc(sizeof(char) *
					(strlen(str)+1));
			strcpy(allwords[(*counter)++], str);
		}
	}

	return allwords;
}

int normalize(char **allwords, int nwords) {
	int i, len, maxlength=0;

	// qual eh a string mais longa
	for (i = 0; i < nwords; i++) {
		if (strlen(allwords[i]) > maxlength) {
			maxlength = strlen(allwords[i]);
		}
	}

	// normalizacao
	//
	// allwords (char **)
	//    |
	//    -----> 	char *  ---> "teste   \0"
	//    		char *  ---> "testando\0"
	//
	/*
		"teste   \0"
		"teste  e\0"
		"teste te\0"
		"testeste\0"
		"testeste\0"
		"testeste\0"
		"te teste\0"
		"t  teste\0"
		"   teste\0"

		last = strlen(allwords[i])-1;
		for (j=maxlength-1; j>=0; j--) {
			allwords[i][j] = last >= 0 ? allwords[i][last--] : ' ';
		}

	 */
	for (i = 0; i < nwords; i++) {
		allwords[i] = (char *) realloc(allwords[i], 
				sizeof(char) * (maxlength+1));
		len = strlen(allwords[i]);
		for (; len < maxlength; len++) allwords[i][len] = ' ';
		allwords[i][len] = '\0';
	}

	return maxlength;
}

// Falta uma função unique words aqui...
char **unique(char **allwords, int nwords, int *newwords) {
	// allwords (char **)
	//    |
	//    ------> 	char * ---> "teste   \0"
	//    		char * ---> "testando\0"
	//    		char * ---> "testando\0" << i = 2
	//    		char * ---> "testando\0"
	//    		char * ---> "teste   \0"
	//
	// uniquewords (char **)
	//    |
	//    ------>  	char * ---> "teste   \0"
	//    	       	char * ---> "testando\0"
	
	int i, j;
	char **uniquewords = NULL;
	*newwords = 0;

	for (i = 0; i < nwords; i++) {
		for (j=0; j<*newwords && strcmp(allwords[i], uniquewords[j]); j++);
		if (j == *newwords) {
			// não foi  inclusa...
			uniquewords = (char **) realloc(uniquewords,
					sizeof(char *) * (*newwords + 1));
			uniquewords[*newwords] = (char *) malloc(sizeof(char)
					* (strlen(allwords[i])+1));
			strcpy(uniquewords[*newwords], allwords[i]);
			(*newwords)++;
		}
	}

	return uniquewords;
}

char *vec2char(double *vec, int length) {
	int i, j;
	char *string = (char *) calloc((length/BITS_IN_BYTE)+1, sizeof(char));

	for (i = 0; i < length/BITS_IN_BYTE; i++) {
		for (j = 0; j < BITS_IN_BYTE; j++) 
			if (vec[i*BITS_IN_BYTE+j] > 0) string[i] |= 128 >> j;
	}
	string[i] = '\0';

	return string;
}

double *char2vec(char *str, int length) {
	int i, j, k;
	double *vector;

	// "testando\0"   ---> length = 8
	// 't' = 0  1 1 1  0 1  0  0
	//       -1 1 1 1 -1 1 -1 -1
	// 'e' = 0 1 1  0  0 1  0 1
	//      -1 1 1 -1 -1 1 -1 1
	// ...
	//
	//       -1 1 1 1 -1 1 -1 -1 -1 1 1 -1 -1 1 -1 1 ...
	vector = (double *) malloc(sizeof(double) * length * BITS_IN_BYTE);

	j = 0;
	for (i = 0; i < length; i++) {
		// 't' = 01110100 AND
		//       01000000
		//       ========
		//       01000000
		for (k = 0; k < BITS_IN_BYTE; k++)
			vector[j++] = (str[i] & (128 >> k)) > 0 ? 1 : -1;
	}

	return vector;
}

// a palavra mais longa do conjunto de palavras
//
// "test        "  -> vetor {-1, +1}
// "abababababab"  -> vetor {-1, +1}
double **vectors(char **uniquewords, int nwords, int maxlength) {
	double **allvectors;
	double *vec;
	int i;

	// Etapa de conversao de cada palavra para um vetor
	allvectors = matrix_create(nwords, maxlength * BITS_IN_BYTE);

	for (i = 0; i < nwords; i++) {
		vec = char2vec(uniquewords[i], maxlength); // double *vec
		memcpy(allvectors[i], vec, maxlength*BITS_IN_BYTE*sizeof(double));
		free(vec);
	}

	return allvectors;
}















