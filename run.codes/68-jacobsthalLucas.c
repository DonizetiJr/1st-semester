#include <stdlib.h>
#include <stdio.h>
#include <math.h>


double jacobsthal_lucas(int n) {
   if(n == 0) return 2.0;
   else if(n == 1) return 1.0;
   else
      return (2*jacobsthal_lucas(n-2) + jacobsthal_lucas(n-1));
}

double *create_jacobsthal_lucas(int n) {
   int i;
   double *numbers;

   numbers = (double *)malloc(sizeof(double)*n);

   for(i = 0; i < n; i++)
      numbers[i] = jacobsthal_lucas(i);
   return numbers;
}

void print_jacobsthal_lucas(int n, double *numbers) {
   int i;

   for(i = 0; i < n; i++)
      printf("%.1lf ", numbers[i]);
   printf("\n");

   return;
}

double media(double *numbers, int qnt) {
   int i;
   double media = 0;

   for(i = 0; i < qnt; i++)
      media += numbers[i];
   media /= qnt;

   return media;
}

void print_variance(int n, double *numbers) {
   int i;
   double med, variance, sum = 0;

   med = media(numbers, n);
   for(i = 0; i < n; i++)
      sum += pow((numbers[i]- med),2);
   variance = (1.0/n)*sum;

   printf("%.4lf\n", variance);
   return;
}

double max(int n, double *numbers) {
   int i;
   double max = 0;

   for(i = 0; i < n; i++)
      if(numbers[i] > max) max = numbers[i];

   return max;
}

void print_chebyshev(int n, double *numbers) {
   int middle, i;
   double chebyshev;
   double *distances;
   middle = n/2;

   distances = (double *)malloc(sizeof(double)*middle);

   for(i = 0; i < middle; i++)
      distances[i] = fabs(numbers[i]-numbers[middle+i]);
   chebyshev = max(n, distances);
   printf("%.4lf\n", chebyshev);

   return;
}

int main(int argc, char *argv[]) {
   int n, op;
   double *numbers;
   scanf("%d %d", &op, &n);

   numbers = create_jacobsthal_lucas(n);

   switch(op) {
      case 1:
         print_jacobsthal_lucas(n, numbers);
         break;
      case 2:
         print_variance(n, numbers);
         break;
      case 3:
         print_chebyshev(n, numbers);
         break;
      default:
         printf("Unknown Operator\n");
   }
   free(numbers);

   return 0;
}
