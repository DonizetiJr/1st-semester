#include <stdlib.h>
#include <stdio.h>

int main (int argc, char *argv[]) {

	int i;
	double n;
	scanf("%lf", &n);

	for(i = 1; i <= (2*n)-1; i += 2) {
		printf("%d\n", i);
	}



	return 0;
}