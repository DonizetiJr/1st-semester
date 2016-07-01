#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main( int argc, char *argv[ ] ) {
  
	int count;

   if (argc > 0) {
      
      for (count = 1; count < argc; count++) {
      	if(strcmp(argv[count], "-i") == 0)
      		printf("E aí?!\n");
      	if(strcmp(argv[count], "-h") == 0)
      		printf("Me ajude!\n");
      	if(strcmp(argv[count], "-q") == 0)
      		printf("Vlw! Flw!\n");
	   }
	 }
  return 0;
}