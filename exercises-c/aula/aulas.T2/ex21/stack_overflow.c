#include <stdio.h>

// ulimit -s			# stack size in Kbytes
void stack_overflow() {
	char c;
	printf("Endereco: %p\n", &c);
	stack_overflow();
}

int main(int argc, char *argv[]) {

	stack_overflow();

	return 0;
}
