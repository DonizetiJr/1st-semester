#include <stdlib.h>
#include <stdio.h>



int main(int argc, char *argv[]) {

	int num, contrario, aux;

	scanf("%d", &num);

	aux = num;
	contrario = 0;

	while (aux != 0) {
		contrario = contrario*10 + aux % 10;
		aux = aux/10;
	}

	if(contrario == num)
		printf("SIM");
	else
		printf("NAO");

	return 0;
}