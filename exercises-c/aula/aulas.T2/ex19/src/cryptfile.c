#include <stdlib.h>
#include <stdio.h>
#include <crypt.h>
#include <matrix.h>
#include <file.h>

#define ROWS 8
#define COLS 8

enum {
	PROGNAME,
	KEYFILE,
	INPUTFILE,
	OUTPUTFILE,
	NARGS
};

int main(int argc, char *argv[]) {
	double **K;
	byte *stream, *crypted;
	long n;
	FILE *fpkey;

	if (argc != NARGS) {
		printf("usage: %s keyfile inputfile outputfile\n", argv[PROGNAME]);
		return -1;
	}

	// Carregar o arquivo de chave de criptografia...
	fpkey = fopen(argv[KEYFILE], "r");
	if (fpkey == NULL) {
		printf("Could not open keyfile: %s\n", argv[KEYFILE]);
		return -2;
	}
	K = matrix_create(ROWS, COLS);
	matrix_fread(fpkey, K, ROWS, COLS);
	fclose(fpkey);

	// Ler o arquivo a ser criptografado...
	stream = readFullFile(argv[INPUTFILE], &n);

	// Criptografar...
	crypted = crypt(stream, (int) n, K, ROWS, COLS);

	// Salvar em um arquivo...
	writeFullFile(argv[OUTPUTFILE], crypted, n*64);

	free(stream);
	free(crypted);
	matrix_free(K, ROWS);

	return 0;
}













