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

void funcao(enum VARTYPE type, union VARIABLE var) {

	switch (type) {
		case CHAR: 
			printf("char: %c\n", var.c);
			break;
		case INT:
			printf("int: %d\n", var.i);
			break;
		case DOUBLE:
			printf("double: %lf\n", var.d);
			break;
		case PCHAR:
			printf("char *: %p\n", var.p);
			break;
		case SHORT:
			printf("short: %d\n", var.s);
			break;
	}
}

int main(int argc, char *argv[]) {
	enum VARTYPE type;
	union VARIABLE var;

	type = SHORT;
	var.p = (char *) 0x6346A;

	funcao(type, var);

	return 0;
}











