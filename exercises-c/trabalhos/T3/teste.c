#include <stdlib.h>
#include <stdio.h>


int *receiveData(int *dados, int amount) {
	int i;
	//Aloca na Heap (4*quantidade de dados) bytes
	dados = (int *)malloc(sizeof(int)*amount);

	for(i=0; i< amount; i++)	
		 scanf("%d", &dados[i]); //recebe os numeros digitados
	return dados;
}

int **hash(int amount, int k, int *vp, int **vd) {
	int module, i;
	//contador para determinar o numero de colisões em determinado índice:
	int *counter;

	counter = (int *)calloc(k,sizeof(int)*k);
	vd = calloc(k,sizeof(int *)*k); //usa-se "calloc" pois pode não ser atribuído valores a todas as células, 
											 //assim, as células "vazias" imprimirão 0 
	for(i=0; i<amount;i++) {
		module = vp[i]%k; // resto entre a chave e k
		
		vd[module] = (int *)realloc(vd[module], sizeof(int)*(counter[module]+1));
		vd[module][counter[module]] = vp[i]; //armazena o valor digitado na célula correspondente
		counter[module]++; // Se houver colisão, o próximo valor associado será armazenado na célula seguinte
	}
	free(vp); //o vetor vp não será mais utilizado, pois vd contém seus valores organizados 
	free(counter);
	return vd;
}

void printTable(int k, int **vd) {
	int i, j;
	
	for(i=0;i<k;i++) {
		printf("%d: ", i); // imprime o índice da tabela

		if(vd[i] == 0){ // se não houve valor associado nada será impresso
		 	printf("\n");
		} else {
			for(j=0;vd[i][j]!=0;j++) { //imprimir até que não haja mais valores associados ao índice
				printf("%d ",vd[i][j]);
			}
			printf("\n");
		}
	}
}

int main(int argc, char *argv[]) {

	int k, n, i, j;
	int *vp; // Ponteiro que receberá o endereço dos dados
	int **vd;// Ponteiro que apontará para os dados organizados
	scanf("%d %d", &k, &n);// Pede k e a quantidade de dados a serem armazenados:

	vp = receiveData(vp, n); //recebe o endereço dos numeros armazenados na Heap
	vd = hash(n, k, vp, vd); //recebe o endereço dos dados já organizados
	printTable(k, vd); // função que imprimirá a Tabela de Dispersão

	for(i=0; i<k;i++) //Libera todos os valores que o vetor vd aponta
		free(vd[i]);
	free(vd);

	return 0;
}