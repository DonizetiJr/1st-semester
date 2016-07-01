#include <stdlib.h>
#include <stdio.h>

void funcao(void) {
	printf("Hello World.\n");
}

int *create(int n) {
	int *vector = (int *) malloc(sizeof(int) * n);
	printf("Hello World2.\n");
	return vector;
}

int main(int argc, char *argv[]) {
	int *vec;
	void (*ponteiro) (void); // ponteiro para uma funcao
			// retorna void e recebe void
	int * (*ponteiro2) (int);

	ponteiro = &funcao;
	ponteiro();

	ponteiro2 = &create;
	vec = ponteiro2(5);
	free(vec);

	return 0;
}
