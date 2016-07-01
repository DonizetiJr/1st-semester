#include <stdio.h>

int main(int argc, char *argv[]) {
  
  int i1, j1, i2, j2, i, j, k;
    
  //Matriz M
  scanf("%d %d", &i1, &j1);
  //Matriz N
  scanf("%d %d", &i2, &j2);
  
  int mM[i1][j1];
  int mN[i2][j2];

  if (j1 == i2) {
    for (i=0; i<i1; i++) {
      for(j=0; j<j1; j++) {
        scanf("%d", &mM[i][j]);
      }
    }
    for (i=0; i<i2; i++) {
      for (j=0; j<j2; j++) {
        scanf("%d", &mN[i][j]); 
      }
    }

    //Multiplicação
    int m3[i1][j2];
    for (i=0;i<i1; i++) {
      for (j=0; j<j2; j++) {
        m3[i][j] = 0;
        for (k=0; k<j1; k++) {
          m3[i][j] = m3[i][j] + (mM[i][k] * mN[k][j]); 
        }
        printf("%d ", m3[i][j]);
      }
    printf("\n");
    }
  }
    
return 0;    
}