#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {

	int a, b, c;
	int hipotenusa, cateto1, cateto2;
	scanf("%d %d %d", &a, &b, &c);

	if (a > b && a > c){
		hipotenusa = a;
		cateto1 = b;
		cateto2 = c;
	} else if (b > c) {
		hipotenusa = b;
		cateto1 = a;
		cateto2 = c;
	} else {
		hipotenusa = c;
		cateto1 = a;
		cateto2 = b;
	}

	if (pow(hipotenusa, 2) == pow(cateto1, 2) + pow(cateto2, 2)) {
		printf("SIM");
	} else {
		printf("NAO");
	}


	return 0;
}