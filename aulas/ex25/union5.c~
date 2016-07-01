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
	union VARIABLE *v;
};

// sched.c task.h		kernel.org
void funcao(struct TYPE *vstruct) {

	switch (vstruct->t) {
		case CHAR: 
			printf("char: %c\n", vstruct->v->c);
			break;
		case INT:
			printf("int: %d\n", vstruct->v->i);
			break;
		case SHORT:
			printf("short: %d\n", vstruct->v->s);
			break;
		case DOUBLE:
			printf("double: %lf\n", vstruct->v->d);
			break;
		case PCHAR:
			printf("char *: %p\n", vstruct->v->p);
			break;
	}
}

int main(int argc, char *argv[]) {
	//struct TYPE var; // Stack
	struct TYPE *pvar;

	printf("Sizeof enum = %d\n", sizeof(enum VARTYPE));
	printf("Sizeof union = %d\n", sizeof(union VARIABLE));
	printf("Sizeof struct = %d\n", sizeof(struct TYPE));

	pvar = (struct TYPE *) malloc(sizeof(struct TYPE));

	pvar->t = SHORT;
	pvar->v = (union VARIABLE *) malloc(sizeof(union VARIABLE));
	pvar->v->p = (char *) 0x6346A;

	funcao(pvar);

	free(pvar->v);
	free(pvar);

	return 0;
}











