#include <stdio.h>


int main(int argc, char *argv[]) {

	int i, maior;
	int vendas[31];

	maior = 0;
	for(i=0;i<31;i++) { 
		scanf("%d", &vendas[i]);
		if(vendas[i] > maior) 
			maior = vendas[i];
	}
	printf("%d\n", maior);

	for(i=0;i<31;i++) {
		if(vendas[i] == maior)
			printf("%d\n", i+1);
	}

	return 0;
}