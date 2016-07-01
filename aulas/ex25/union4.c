#include <stdlib.h>
#include <stdio.h>

enum VARTYPE {
	CHAR,
	INT,
	DOUBLE,
	PCHAR,
	SHORT
};

union VARIABLE { // 8 bytes
	char c;
	int i;
	double d;
	char *p;
	short s;
};

struct TYPE {
	enum VARTYPE t;
	union VARIABLE v;
};

void funcao(struct TYPE *vstruct) {

	switch (vstruct->t) {
		case CHAR: 
			printf("char: %c\n", vstruct->v.c);
			break;
		case INT:
			printf("int: %d\n", vstruct->v.i);
			break;
		case DOUBLE:
			printf("double: %lf\n", vstruct->v.d);
			break;
		case PCHAR:
			printf("char *: %p\n", vstruct->v.p);
			break;
		case SHORT:
			printf("short: %d\n", vstruct->v.s);
			break;
	}
}

int main(int argc, char *argv[]) {
	//struct TYPE var; // Stack
	struct TYPE *pvar;

	pvar = (struct TYPE *) malloc(sizeof(struct TYPE));

	pvar->t = SHORT;
	pvar->v.p = (char *) 0x6346A;

	funcao(pvar);

	free(pvar);

	return 0;
}











