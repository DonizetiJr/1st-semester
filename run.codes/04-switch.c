#include <stdio.h>
#include <stdlib.h>

int main() {

	float a, b;
	char op;

	scanf("%f %c %f", &a, &op, &b);



	switch(op) {

		case '+':
			printf("%f\n", a+b);
			break;
		case '-':
			printf("%f\n", a-b);
			break;
		case '*':
			printf("%f\n", a*b);
			break;
		case '/':
			printf("%f\n", a/b);
			break;
		case '%':
			printf("%f\n", (100*a)/b);
			break;

		default:
			("operador desconhecido\n");
	}

	return 0;
}