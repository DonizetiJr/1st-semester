#include <stdio.h>
#include <vaargs.h>

int main(int argc, char *argv[]) {
	// constante (string não pode ser alterada)
	const char *str = "abababababa";

	print("Hello...%d %f %c %s\n", 17, 1.23f, 'A', str);

	return 0;
}
