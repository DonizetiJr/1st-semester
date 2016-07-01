#include <stdio.h>
#include <vaargs.h>

int main(int argc, char *argv[]) {
	double res;

	res = sum(3, 1.2, 5.6, 9.3);

	printf("Total: %lf\n", res);

	return 0;
}
