#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SPACE 32
char frase[1000]; //usar readLine()

int main( int argc, char *argv[ ] ) {

	int jump;

	scanf("%d\n", &jump);
	scanf("%[^\n]s", frase);

	int i;
	for(i = 0; i < strlen(frase); i++) {
		
		if(frase[i] == SPACE){
			printf("%c", SPACE);
		} else {
			char cifra = (frase[i] + jump);
				if(cifra > 'Z')	
					printf("%c", cifra-26);
				else if (cifra)
					printf("%c", cifra);
		}
	}



return 0;
}