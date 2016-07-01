#include <stdio.h>
 
double seq_lucas(int n) {
   if (n == 0) return 2;
   else if (n == 1) return 1;
   else 
      return (seq_lucas(n-1.0) + seq_lucas(n-2.0));
}

int main(int argc, char *argv[]) {
    int n;
    scanf("%d", &n);

    printf("%lf\n", seq_lucas(n));

    return 0;
}