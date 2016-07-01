#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
	int i;
	char *p;
	char *aux;

	p = (char *) malloc(sizeof(char) * 3);
	aux = p;

	for (i = 0; i < 3; i++) {
		//(*aux)++ = 'A'+i;  -> não executa
		
		// opção
		// - 
		//
		printf("end antes = %p\n", aux);
		*(aux++) = 'A'+i;
		//*aux++ = 'A'+i;
		printf("end depois = %p\n\n", aux);

		//		     ------
		//                   |    |
		//                   | 65 |
		//                   | 66 |
		//                   ------
		// aux ----------->   67??? (SEG FAULT)
	}

	for (i = 0; i < 3; i++) {
		printf("%c (%p)\n", *(p+i), p+i);
	}

	free(p);

	return 0;
}
