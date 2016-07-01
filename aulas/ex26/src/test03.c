#include <stdio.h>
#include <vaargs.h>

int main(int argc, char *argv[]) {

	print("Resultado: %f\n", (float) sum(5, 1.2, 4.5, 1.2, 9.8, 19.23));

	return 0;
}
