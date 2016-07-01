#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main( int argc, char *argv[ ] ) {

	int i, resultado;

	if(argc > 0) {

		if (strcmp(argv[1], "+") == 0){
			for (i = 2; i < argc; i++) {
				resultado += atoi(argv[i]);
			}
		}
		if (strcmp(argv[1], "-") == 0){
			resultado = atoi(argv[2]);
			for (i = 3; i < argc; i++) {
				resultado -= atoi(argv[i]);
			}
		}
	}
	printf("%d", resultado);



return 0;
}