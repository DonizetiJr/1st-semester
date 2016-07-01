#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double tetranacci(int n) {
   if (n == 0) return 0;
   else if (n == 1) return 0;
   else if (n == 2) return 1.0;
   else if (n == 3) return 1.0;
   else
      return (tetranacci(n-4.0) + tetranacci(n-3.0) +
               tetranacci(n-2.0)+ tetranacci(n-1.0));
}

double *create_tetranacci(int n) {
   int i;
   double *numbers;

   numbers = (double *)malloc(sizeof(double)*n);

   for(i = 0; i < n; i++)
      numbers[i] = tetranacci(i);
   return numbers;
}

void print_tetranacci(double *numbers, int n) {
   int i;

   for(i = 0; i < n; i++)
      printf("%.1lf ", numbers[i]);
   printf("\n");

   return;
}

void media_quad(double *numbers, int qnt) {
   int i;
   double media, sum = 0;

   for(i = 0; i < qnt; i++) sum += pow(numbers[i],2);
   media = sqrt(sum/qnt);

   printf("%.4lf\n", media);
   return;
}

void manhattan_dist(double *numbers, int qnt) {
      int n, i;
      double sum = 0;
      n = qnt/2;

      for(i = 0; i < n; i++)
         sum += fabs(numbers[i]-numbers[n+i]);

      printf("%.4lf\n", sum);
   return;
}

int main(int argc, char *argv[]) {
   int n, op;
   double *numbers;
   scanf("%d %d", &op, &n);

   numbers = create_tetranacci(n);

   switch(op) {
      case 1:
         print_tetranacci(numbers, n);
         break;
      case 2:
         media_quad(numbers, n);
         break;
      case 3:
         manhattan_dist(numbers, n);
         break;
      default:
         printf("Unknown Operator\n");
   }
   free(numbers);

    return 0;
}
