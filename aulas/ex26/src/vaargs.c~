#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

/*
char *int2char(int i) {
	// 00000000 00000000 00000000 00110001	= 49
}
*/

void print(const char *s, ...) {
	// s -> "Hello World %d %c %s %f\n"
	va_list args;
	//char *str;

	va_start(args, s);
	while (*s != '\0') {

		switch (*s) {
			case '%': 
				s++;

				switch (*s) {
					case 'd': 
						printf("%d", va_arg(args, int));
						/*
						//putc(va_arg(args, int), stdout);
						str = int2char(va_arg(args, int));
						while (*str != '\0') {
							putc(*str, stdout);
							str++;
						}
						free(str);*/
						break;
					case 'c': 
						printf("%c", (char) va_arg(args, int));
						break;
					case 's': 
						printf("%s", va_arg(args, char *));
						break;
					case 'f': 
						printf("%f", (float) va_arg(args, double));
						break;
				}

				break;
			default:
				//printf("%c", *s);
				putc(*s, stdout);
				break;
		}

		s++;
	}
	va_end(args);
}

double sum(int number, ...) {
	int i;
	va_list args;
	double param, total = 0.0;

	// Inicializa args para aponta para o segundo argumento da função
	va_start(args, number);

	for (i = 0; i < number; i++) {
		param = va_arg(args, double);
		total += param;
	}
	va_end(args);

	return total;
}

