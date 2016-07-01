#include <stdio.h>

int main(int argc, char *argv[]) {
  long i, j, col, value, n;

  scanf("%ld", &n);
  
  for(i=0; i<n; i++) { 
    col = i+1;
    value = 1;
    printf("%ld",value);

    for(j=1;j<col;j++) {
  	 value = value*(i-j+1)/j;
  	 printf("%ld", value);
    }
   printf("\n");
}

  return 0;
}