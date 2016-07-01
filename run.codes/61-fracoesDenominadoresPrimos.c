#include <stdlib.h>
#include <stdio.h>

int *receive_primos(int n, int *qnt){
   int count, c, i = 3;
   int *prime_numbers = NULL;

   prime_numbers = (int *)realloc(prime_numbers, sizeof(int));
   prime_numbers[0] = 2;
   *qnt = 1;

   for (count = 2 ; count < n ;  count++){
      for (c = 2 ; c <= i - 1 ; c++ )
         if ( i%c == 0 ) break;
      if (c == i) {
         prime_numbers = (int *)realloc(prime_numbers, sizeof(int)*(*qnt+1));
         prime_numbers[(*qnt)++] = i;
      }
      i++;
    }
    return prime_numbers;
}

void prime_serie(int *primes, int n, int qnt) {
   int i, aux = 1;
   double sum = 0;

   for(i = 0; i < qnt; i++) {
      sum += aux*(1.0/primes[i]);
      aux *= -1;
   }
   printf("%lf\n", sum);

   return;
}

int main(int argc, char *argv[]) {
   int n, qnt;
   int *primes;
   scanf("%d", &n);

   primes = receive_primos(n, &qnt);
   prime_serie(primes, n, qnt);

   free(primes);

   return 0;
}
