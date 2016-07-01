#include <stdlib.h>
#include <stdio.h>


int *receiveData(int *dados, int amount) {
	int i;

	for(i=0; i< amount; i++)	
		 scanf("%d", &dados[i]); //recebe os numeros digitados
	return dados;
}

int  **hash(int amount, int k, int *vp, int **vd, int *counter) {
	int module, i;
 
	for(i=0; i<amount;i++) {
		module = vp[i]%k; // resto entre a chave e k
		
		vd[module] = (int *)realloc(vd[module], sizeof(int)*(counter[module]+1));
		vd[module][counter[module]] = vp[i]; //armazena o valor digitado na célula correspondente
		counter[module]++; // Se houver colisão, o próximo valor associado será armazenado na célula seguinte
	}
	free(vp); //o vetor vp não será mais utilizado, pois vd contém seus valores organizados 

	return vd;
}

void printTable(int k, int **vd, int *counter) {
	int i, j;
	
	for(i=0;i<k;i++) {
		printf("%d: ", i);//imprime o índice da tabela

		if(vd[i] == 0){ // se não houve valor associado nada será impresso
		 	printf("\n");
		} else {
			for(j=0;j<counter[i];j++) { //imprimir até que não haja mais valores associados ao índice
				printf("%d ",vd[i][j]);
			}
			printf("\n");
		}
	}
	return;
}

int main(int argc, char *argv[]) {

	int k, n, i;
	int *vp; // Ponteiro que receberá o endereço dos dados
	int *counter; //Ponteiro que contará o numero de colisões
	int **vd;// Ponteiro que apontará para os dados organizados
	scanf("%d %d", &k, &n);// Pede k e a quantidade de dados a serem armazenados:

	//Alocações na Heap:
	vp = (int *)malloc(sizeof(int)*n);
	vd = calloc(k,sizeof(int *)); //usa-se "calloc" pois pode não ser atribuído valores a todas as células, 
											 //assim, as células "vazias" imprimirão 0
	counter = (int *)calloc(k,sizeof(int)); //Ponteiro é zerado para contar a quantidade de colisões
	
	vp = receiveData(vp, n); //recebe o endereço dos numeros armazenados na Heap
	vd = hash(n, k, vp, vd, counter); //organizará os dados de acordo com a Tabela de Dispersão desejada
	printTable(k, vd, counter); //Função que imprimirá a Tabela de Dispersão

	for(i=0; i<k;i++) //Libera tudo que um ponteiro duplo aponta na Heap
		free(vd[i]);
	free(vd);
	free(counter);
	return 0;
}