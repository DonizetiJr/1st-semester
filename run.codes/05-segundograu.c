#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
  
  float a,b,c,d,i,real;
    
  scanf("%f %f %f",&a, &b, &c);

  d=((b*b)-4*(a*c));
        
  if(d==0) {
    printf("DUPLA\n");
    printf("RD %f\n",(-b/2*a));
        
   } else if(d>0){
      printf("REAIS\n");
      printf("R1 %f\n", (-b/2*a)+sqrt(d)/(2*a));
      printf("R2 %f\n",((-b/2*a)-sqrt(d)/(2*a)));
             
    } else if(d<0) {
      
      real=(-b)/(2*a);
      i= sqrt(-d)/(2*a);
      
      printf("COMPLEXAS\n");
      printf("R %f\n", real); 
      printf("I %f\n", i);
    }

return 0;

}