#include <stdlib.h>
#include <stdio.h>
#include <utils.h>

byte *readFullFile(char *filename, long *n) {
	FILE *fp;
	byte *stream;

	fp = fopen(filename, "r");
	if (fp == NULL) return NULL;

	// Descobrir quantos bytes o arquivo tem
	fseek(fp, 0, SEEK_END); // vai para o final do arquivo
	*n = ftell(fp);
	
	stream = (byte *) malloc(sizeof(byte) * (*n));
	fseek(fp, 0, SEEK_SET); // a partir do inicio
	fread(stream, sizeof(byte), *n, fp);

	fclose(fp);

	return stream;
}

void writeFullFile(char *filename, byte *stream, long n) {
	FILE *fp;

	fp = fopen(filename, "w+");
	if (fp == NULL) {
		printf("Could not write into %s\n.", filename);
		return;
	}

	fwrite(stream, sizeof(byte), n, fp);
	fclose(fp);
}

















