#include <stdlib.h>
#include <stdio.h>

void rollDice(int *n, int *qnt) {
	*qnt = 0;
	while(scanf("%d", &n[*qnt]) != EOF) {
		(*qnt)++;
		n = (int *)realloc(n, sizeof(int)*(*qnt+1));
	} //No terminal, para parar o loop deve-se aperta Ctrl+D!
	return;
}

void frequence(int *n, int *qnt) {
	int i, bigger;
	int *counter;
	counter = (int *)calloc(6,sizeof(int));

	for(i=0; i < *qnt; i++) counter[n[i]-1]++;

	bigger = 0;
	for(i=0; i < 6; i++) 
		if(counter[i] > bigger) bigger = counter[i];

	for(i=0; i < 6; i++)
		if(counter[i] == bigger) printf("%d\n", i+1);
	printf("%d\n", bigger);

	free(counter);

	return;
}


int main(int argc, char *argv[]) {
	int qnt;
	int *n = NULL;

	n = (int *)realloc(n, sizeof(int));
	rollDice(n, &qnt);
	frequence(n, &qnt);

	free(n);

	return 0;
}