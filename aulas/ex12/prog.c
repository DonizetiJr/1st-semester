#include <stdlib.h>
#include <stdio.h>

unsigned char *readAudio(char *inputfilename, int *counter) {
	FILE *fp;
	unsigned char amplitude;
	unsigned  char *content = NULL;
	counter[0] = 0;

	fp = fopen(inputfilename, "r");
	if (fp == NULL) {
		printf("Cannot open file.\n");
		exit(0);
	}

	while (!feof(fp)) {
		fread(&amplitude, sizeof(unsigned  char), 1, fp);
		if (!feof(fp)) {
			// amplitude tem um valor útil
			content = (unsigned char *) realloc(content,
					sizeof(unsigned char) * (counter[0]+1));
			content[counter[0]++] = amplitude;
		}
	}

	fclose(fp);

	return content;
}

void writeAudio(char *outputfilename, unsigned char *newaudio, int counter) {
	FILE *fp;
	int i;

	fp = fopen(outputfilename, "w");
	if (fp == NULL) {
		printf("Cannot open file.\n");
		exit(0);
	}

	for (i = 0; i < counter; i++) {
		fwrite(&newaudio[i], sizeof(unsigned char), 1, fp);
	}

	fclose(fp);
}

void printAudio(unsigned char *content, int counter) {
	int i;

	for (i = 0; i < counter; i++) {
		fprintf(stdout, "%d\n", content[i]);
	}
}

unsigned char *reduceSymbols(unsigned char *content, int counter, int nSymbols) {
	int i, step, interval;
	unsigned char *result = 
		(unsigned char *) malloc(sizeof(unsigned char) * counter);
	double *symbolsAverage = (double *) calloc(nSymbols, sizeof(double));
	int    *symbolsCounter = (int *) calloc(nSymbols, sizeof(int));
	
	step = 256 / nSymbols;

	for (i = 0; i < counter; i++) {
		// em qual intervalo ele está?
		interval = content[i] / step;
		if (interval > nSymbols-1) {
			interval = nSymbols-1; // gambiarra!! ;)
		}
		symbolsAverage[interval] = symbolsAverage[interval] + content[i];
		symbolsCounter[interval]++;
	}

	// Encontrando as medias por intervalo
	for (i = 0; i < nSymbols; i++) {
		symbolsAverage[i] = symbolsAverage[i] / symbolsCounter[i];
	}

	for (i = 0; i < counter; i++) {
		interval = content[i] / step;
		if (interval > nSymbols-1) {
			interval = nSymbols-1; // gambiarra!! ;)
		}
		result[i] = symbolsAverage[interval];
	}

	free(symbolsAverage);
	free(symbolsCounter);

	return result;
}

enum {
	PROGNAME, 	// 0
	INPUTFILE, 	// 1
	OUTPUTFILE, 	// 2
	NSYMBOLS,	// 3
	NARGS		// 4
};

int main(int argc, char *argv[]) {
	int counter, nSymbols;
	unsigned char *content, *newsignal;

	if (argc != NARGS) {
		printf("usage: %s inputfile outputfile nsymbols\n", argv[PROGNAME]);
		return 1;
	}

	nSymbols = atoi(argv[NSYMBOLS]); // char * -> int
	content = readAudio(argv[INPUTFILE], &counter);
	//printAudio(content, counter);
	newsignal = reduceSymbols(content, counter, nSymbols);
	//printAudio(newsignal, counter);
	writeAudio(argv[OUTPUTFILE], newsignal, counter);

	free(content);
	free(newsignal);

	return 0;
}



















