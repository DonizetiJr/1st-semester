#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[]) {

	int i, inteiro, decimal;

	for (i = 1000; i < 10000; i++) {
		inteiro = i/100;
		decimal = i%100;

		if(sqrt(i) == inteiro + decimal)
			printf ("%d\n", i);
	}

	return 0;
}