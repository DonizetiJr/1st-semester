#include <stdlib.h>
#include <stdio.h>
#include <file.h>
#include <utils.h>
#include <preprocessing.h>

enum {
	PROGNAME,
	FILENAME,
	NARGS
};

int main(int argc, char *argv[]) {
	byte *stream;
	long n;
	char *strings;
	char **allwords;
	int i, nwords;

	if (argc != NARGS) {
		printf("usage: %s filename\n", argv[PROGNAME]);
		return -1;
	}

	stream = readFullFile(argv[FILENAME], &n);
	strings = preprocessing(stream, n);

	printf("preprocessed: %s\n\n", strings);

	allwords = words(strings, &nwords);

	for (i = 0; i < nwords; i++) {
		printf("%s\n", allwords[i]);
	}

	//printf("Endereco de strings: %p\n", strings);

	free(stream);
	free(strings);

	for (i = 0; i < nwords; i++) {
		//printf("Endereco de allwords[%d]: %p\n", i, allwords[i]);
		free(allwords[i]);
	}
	free(allwords);

	return 0;
}













