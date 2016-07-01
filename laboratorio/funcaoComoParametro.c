#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

#define ENTER 10

char *readLine(FILE *stream, char del) {
   char c;
   char *string = NULL;
   int counter = 0;

   do {
      c = fgetc(stream);

      string = (char *)realloc(string, sizeof(char) * (counter+1));
      string[counter++] = c;
   } while (c != ENTER && c != del);

   string[counter-1] = '\0';

   return string;

}

double average(int no_args, ... ) {
   double result = 0, i;
   va_list ap;

   va_start(ap, no_args);

   for (i = 1; i <= no_args; i++)
      result += va_arg(ap, int);
   result /= no_args;

   va_end(ap);

   return result;
}


double soma(double a, double b) {
   return a + b;
}

double subtracao(double a, double b) {
   return a - b;
}

double multiplicacao(double a, double b) {
   return a * b;
}

double divisao(double a, double b) {
   if(b == 0) return 0;
   return a / b;
}

double opera(double a, double b, double operacao(double, double)) {

	return operacao(a, b);
}

int main(int argc, char *argv[]) {

   int n, opcao, i;
   //int count;
   double a, b;
   char *str;

	opcao = atoi(readLine(stdin, ENTER));

	switch(opcao) {
		case 1:
			if (argc > 1) {
			   for (i = 0; i < argc; i++)
				   printf("argv[%d] = %s\n", i, argv[i]);
			} else {
			      printf("The command had no other arguments.\n");
			}

		case 2:
			str = readLine(stdin, ' ');
         a = atof(str);
         free(str);

			str = readLine(stdin, ' ');
         n = str[0];
         free(str);

			str = readLine(stdin, ' ');
         b = atof(str);
         free(str);

   		switch(n) {
            // Soma
   			case '+':
   				printf("%lf\n", opera(a, b, soma));
   				break;

   			// Subtracao
   			case '-':
      			printf("%lf\n", opera(a, b, subtracao));
      			break;

      		// Multiplicacao
      		case '*':
      		   printf("%lf\n", opera(a, b, multiplicacao));
      			break;

      		// Divisao
      		case '/':
      			printf("%lf\n", opera(a, b, divisao));
      			break;
      		}
      	   break;

		case 3:
	   	printf("Average of 2, 3, 4, 5 = %f\n", average(4, 2,3,4,5));
			printf("Average of 5, 10, 15 = %f\n", average(3, 5,10,15));
			printf("Average of 3, 11, 12 = %f\n", average(3, 3,11,12));
			printf("Average of 1, 1 = %f\n", average(1, 1));
			break;
	}

	return 0;
}
