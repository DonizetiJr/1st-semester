#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double tribonacci(int n) {
   if (n == 0) return 0;
   else if (n == 1) return 0;
   else if (n == 2) return 1.0;
   else
      return (tribonacci(n-3.0) + tribonacci(n-2.0)+ tribonacci(n-1.0));
}

double *create_tribonacci(int n) {
   int i;
   double *numbers;

   numbers = (double *)malloc(sizeof(double)*n);

   for(i = 0; i < n; i++)
      numbers[i] = tribonacci(i);
   return numbers;
}

void print_tribonacci(int n, double *numbers) {
   int i;

   for(i = 0; i < n; i++)
      printf("%.1lf ", numbers[i]);
   printf("\n");

   return;
}

void print_media(double *numbers, int qnt) {
   int i;
   double result = 0;

   for(i = 0; i < qnt; i++)
      result += numbers[i];
   result /= qnt;

   printf("%.4lf\n", result);
   return;
}

double media(double *numbers, int init, int end) {
   int i;
   double result = 0;

   for(i = init; i < end; i++)
      result += numbers[i];
   result /= (end-init);

   return result;
}

void pearson_seq(double *numbers, int qnt) {
      int n, i;
      double sum1 = 0, sum2 = 0, sum3 = 0, media_x, media_y, p;
      n = qnt/2;

      media_x = media(numbers, 0, n);
      media_y = media(numbers, n, qnt);

      for(i = 0; i < n; i++) {
         sum1 += (numbers[i] - media_x)*(numbers[n+i] - media_y);
         sum2 += (numbers[i] - media_x)*(numbers[i] - media_x);
         sum3 += (numbers[n+i] - media_y)*(numbers[n+i] - media_y);
      }
      p = sum1/(sqrt(sum2)*sqrt(sum3));

      printf("%.4lf\n", p);
   return;
}

int main(int argc, char *argv[]) {
   int n, op;
   double *numbers;
   scanf("%d %d", &op, &n);

   numbers = create_tribonacci(n);

   switch(op) {
      case 1:
         print_tribonacci(n, numbers);
         break;
      case 2:
         print_media(numbers, n);
         break;
      case 3:
         pearson_seq(numbers, n);
         break;
      default:
         printf("Unknown Operator\n");
   }
   free(numbers);

    return 0;
}
