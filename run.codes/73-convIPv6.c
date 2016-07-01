#include <stdlib.h>
#include <stdio.h>

void dec2hex(int *num) {
   int i = 1, j, k, quocient, temp;
   char **hexa_num;

   hexa_num = (char **)calloc(4, sizeof(char *));

   for(j = 0; j < 4; j++) {
      quocient = num[j];

      while(quocient != 0) {
         temp = quocient % 16;
         //convert integer into character
         if(temp < 10)
            temp += 48;
         else
            temp += 87;

         hexa_num[j] = (char *)realloc(hexa_num, sizeof(char)*i);
         hexa_num[j][i++] = temp;
         printf("%c", hexa_num[j][1]);
         quocient /= 16;
      }
      //for(k = i-1; k > 0; k--) {
         //printf("%c", hexa_num[j][k]);
      //}
      i = 1;
   }
   for(j = 0; j < 4; j++) free(hexa_num[j]);
   free(hexa_num);
   return;
}

int main(int argc, char *argv[]) {
   int *i;

   i = (int *)malloc(sizeof(int)*4);
   scanf("%d %d %d %d", &i[0], &i[1], &i[2], &i[3]);

   dec2hex(i);

   free(i);
   return 0;
}
