#include <stdlib.h>
#include <stdio.h>
#include <crypt.h>
#include <matrix.h>
#include <file.h>

#define ROWS 8
#define COLS 8

enum {
	PROGNAME, // 0
	KEYFILE,  // 1
	INPUTFILE,// 2
	OUTPUTFILE,//3
	NARGS
};

int main(int argc, char *argv[]) {
	double **K, **invK;
	byte *stream, *decrypted;
	long n;
	FILE *fpkey;

	if (argc != NARGS) {
		printf("usage: %s keyfile inputfile outputfile\n", argv[PROGNAME]);
		return -1;
	}

	// Carregar chave
	fpkey = fopen(argv[KEYFILE], "r");
	if (fpkey == NULL) {
		printf("Could not open keyfile: %s\n", argv[KEYFILE]);
		return -2;
	}
	K = matrix_create(ROWS, COLS);
	matrix_fread(fpkey, K, ROWS, COLS);
	fclose(fpkey);

	// Produzir a inversa de K
	invK = matrix_rref(K, ROWS, COLS, TRUE);

	// Ler o arquivo de entrada (crypted)
	stream = readFullFile(argv[INPUTFILE], &n);

	// Descriptografa...
	decrypted = decrypt(stream, (int) n, invK, ROWS, COLS);

	// Salvar no arquivo de saida...
	writeFullFile(argv[OUTPUTFILE], decrypted, n/64);

	matrix_free(K, ROWS);
	matrix_free(invK, ROWS);
	free(stream);
	free(decrypted);

	return 0;
}











