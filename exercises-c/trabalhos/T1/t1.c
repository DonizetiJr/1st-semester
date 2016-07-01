#include <stdio.h>
#include <stdlib.h>

int caracteres() {
	int n;
	scanf("%d\n", &n);

	return n;
}
 
char *readLine(int n) {
	char c;
	char *string = NULL;
	int counter = 0;
	
// Pede ao usuário n caracteres e os armazena na Heap alocada.
	do {
		scanf("%c", &c);
		string=(char *)realloc(string,sizeof(char)*(counter+1));
		string[counter++] = c;
	} while (counter <= n);
	string[counter-1] = '\0';
	
	return string;
}

char validaCifra(char cifra) {
/*	  Verifica se ultrapassa o número de letras no alfabeto,
	  se sim, retira-se o seu módulo com a quantidade de letras do alfabeto.
*/
	if(cifra >=  26)
		cifra %= 26;

	cifra += 65; //Retorna o valor da letra em valores da tabela ASCII.

return cifra;
}


/*	Funções para Cifra de Cesar
	===========================  
*/

char geraCharCesar(char mensagem, int k){
	char cifra; // 1 BYTE
	cifra = (mensagem-65) + k; // Número da letra mais "deslocamento".

	return validaCifra(cifra);
}

void cifraCesar(int n, char *mensagem){
	int k, i; // 4 BYTES
	char cifra; // 1 BYTE

	scanf("%d", &k); // "Deslocamento" da mensagem.

	for(i = 0; i < n; i++) { // Inicia a criptografia dos n caracteres.
		
		if(mensagem[i] >= 65 && mensagem[i] <= 90){ // Converte apenas letras maiúsculas.
			cifra = geraCharCesar(mensagem[i], k);
			printf("%c", cifra);
		} else { // Mantém símbolos, números, etc.
			printf("%c", mensagem[i]);
		}
	}
}



/*	Funções para Cifra de Vigenère
	==============================  
*/

char geraCharVigenere(char mensagem, char chave){
	char cifra;
	cifra = (mensagem-65) + (chave-65); //Soma das posições da mensagem e da chave.

	return validaCifra(cifra);
}

void cifraVigenere(int n, char *mensagem){
	int i, s, counter; // 4 BYTES
	char *chave; 		 // 8 BYTES
	char cifra; 		 // 1 BYTE
	s = caracteres(); // Quantidade de caracteres da chave.
	chave = readLine(s); // Lê a chave digitada.
	
	counter = 0; /*Servirá para ignorar símbolos, números, espaços, etc. 
					   da mensagem, não partindo para a próxima letra da chave. */
	for(i = 0; i < n; i++) {
		
		if(mensagem[i] >= 65 && mensagem[i] <= 90){ //Apenas para letra maiúsculas.

				if(!chave[i-counter]) counter = i; /*Caso o tamanho da mensagem extrapole
																o tamanho da chave, a contagem desta é zerada. */
				cifra = geraCharVigenere(mensagem[i], chave[i-counter]);

			printf("%c", cifra);
		} else {
			printf("%c", mensagem[i]);
			counter++;
		}
	}
}



/* Código principal
	================
*/

int main( int argc, char *argv[ ] ) {

//variáveis
	int n, op, k, s;  // 4 Bytes
	char *mensagem;  //  8 Bytes

	n = caracteres(); //Pede a quantidade de caracteres da mensagem.
	mensagem = readLine(n); /* Lê os n caracteres digitados 
									e armazena seus endereços da Head 
									no ponteiro "mensagem". */
	
	scanf("%d", &op); //Pede o número para chamar a criptografia desejada.
	
	if(op == 1){	
		cifraCesar(n, mensagem);
	}
	if(op == 2){
		cifraVigenere(n, mensagem);
	}
	//Libera a memória alocada na HEAP.
	free(mensagem);

return 0;
}