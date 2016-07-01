#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <crypt.h>
#include <matrix.h>
#include <math.h>

// bitwise operators
double **byte2vec(byte b) {
	int i;
	double **vec;

	vec = matrix_create(8, 1);
	
	for (i = 0; i < 8; i++) {
		vec[7-i][0] = (b >> i) & 1;
	}

	return vec;
}

byte vec2byte(double **x) {
	int i;
	byte b = 0;

	for (i = 0; i < 8; i++) {
		if (round(x[i][0]) != 0) {
			b |= (1 << (7-i));
		}
	}

	return b;
}

// SHA, TLS, BLOWFISH, FISH, TWOFISH...
byte *crypt(byte *stream, int n, double **key, int row, int col) {
	byte *crypted;
	int i;
	double **b, **bT, **x;

	crypted = (byte *) malloc((n*64) * sizeof(byte));
	
	for (i = 0; i < n; i++) {
		x = byte2vec(stream[i]);
		b = matrix_multiplication(key, row, col, x, 8, 1);
		matrix_free(x, 8);
		//
		// b
		// double**------> double * ---> 0.0
		// 		   double * ---> 1.0
		// 		   double * ---> 1.0
		// 		   double * ---> 0.0
		// 		   double * ---> 0.0
		// 		   double * ---> 0.0
		// 		   double * ---> 0.0
		// 		   double * ---> 1.0

		bT = matrix_transpose(b, 8, 1);
		matrix_free(b, 8);
		// b
		// double**------> double * ---> 0.0, 1.0, 1.0, 0.0, ...

		memcpy(crypted+(i*64), bT[0], 64);
		matrix_free(bT, 1);
	}

	return crypted;
}

byte *decrypt(byte *stream, int n, double **inv_key, int row, int col) {
	byte *decrypted;
	int i;
	double **bT, **b, **x;

	decrypted = (byte *) malloc((n / 64) * sizeof(byte));
	
	for (i = 0; i < n / 64; i++) {
		bT = matrix_create(1, 8);
		memcpy(bT[0], stream+(i*64), 64);
		b = matrix_transpose(bT, 1, 8);
		matrix_free(bT, 1);

		x = matrix_multiplication(inv_key, row, col, b, 8, 1);
		matrix_free(b, 8);

		decrypted[i] = vec2byte(x);
		matrix_free(x, 8);
	}

	return decrypted;
}





















