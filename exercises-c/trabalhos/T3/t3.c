#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

//O define substituirá os símbolos que deixariam o código confuso.
#define ENTER 10
#define SPACE ' '
#define COMMA ','
#define DOT '.'
#define COLON ':'
#define OPENBRACK '('
#define CLOSEBRACK ')'
#define PLUS '!'
#define QUESTMARK '?'

char *readLine() {
	char c; 
	char *string = NULL; 
	int counter = 0; 

	do {
		c = fgetc(stdin);
		
		string=(char *)realloc(string,sizeof(char)*(counter+1));
		string[counter++] = c;
	} while (c != ENTER); //recebe do teclado até o Enter.
	string[counter-1] = '\0';
	
	return string;
}

void noFile(char *name, FILE *fp_input) {
	//imprime a mensagem informando o usuário que não foi possível abrir o arquivo
	printf("Error opening file\n");
	//Como o programa será encerrado, fecha-se o arquivo e é liberado o que foi salvo na Heap
	fclose(fp_input);
	free(name);
		exit(-1); // encerra o programa
}

int size(FILE *fp_input) {
	int tamanho;

	fseek(fp_input, 0, SEEK_END); // leva o cursor até o final do arquivo
	tamanho = ftell(fp_input)/4; // como o tamanho do arquivo é informado em bytes,
										 // divide-se por 4, pois cada int utiliza 4 bytes
	fseek(fp_input, 0, SEEK_SET); //volta o cursor para o começo do arquivo
	
	return tamanho;
}

unsigned int *alocateFile(int size, FILE *input_file) {
	unsigned int *file;
	int i;

	file = (unsigned int *)malloc(sizeof(int)*size);
	//São lidos e salvos em "file" todo o conteúdo do arquivo
	fread(file, sizeof(int)*size, size, input_file); 
	fclose(input_file); //Fecha-se o arquivo pois não será mais preciso acessá-lo

	return file;
}

void reverseVec(unsigned int *file, int size) {
	int aux, j, i;
	j = size - 1; //Irá representar o ultimo número do vetor
	i = 0; //Irá representar o primeiro número do vetor 
	/*No while será trocado de posição o primeiro(i) numero com o ultimo(j),
	então o i+1 com o j-1 e assim por diante até i=j, ou seja, a metade do vetor.*/
	while(i < j) {
		aux = file[i];
		file[i] = file[j];
		file[j] = aux;
		i++;
		j--;
	}
}

void map(unsigned int *file, int size, char *name) {
	int k, i;
	long long aux, num; //Usa-se long long pois dependendo do k, aux pode ultrapassar o limite de int
	k = atoi(name); //transforma o nome do arquivo em inteiro para usá-los nas contas

	for(i=0;i<size;i++) {
		aux = pow(10,k+1); 
		num = file[i]%aux; //Separa o número a partir da posição k
		num /= pow(10,k); //O número desejado é isolado do restante
		
		printf("%lld", num); //Imprime um único número
		k = num; //A posição dos dígitos subsequentes será dada pelo dígito anterior
	}
}

unsigned int isValid(unsigned int file) {
	int i, counter = 0;
	unsigned char *byte;
	byte = (unsigned char *)(&file); //"byte" poderá, agora, percorrer por byte os inteiros para os quais 
											  //file aponta.
	
	for(i=0;i<sizeof(int);i++) { //verificará cada byte(por ser um inteiro, 4 vezes)
		//A seguir é verificado se o byte representa um caracter válido.
		if(byte[i] == SPACE | byte[i] == COMMA     | byte[i] == DOT |
			byte[i] == COLON | byte[i] == OPENBRACK | byte[i] == CLOSEBRACK |
			byte[i] == PLUS  | byte[i] == QUESTMARK | byte[i] == '\0') {
			
		counter++; 

		} else if (isalpha(byte[i]) != 0) counter++;
		  else if(isdigit(byte[i]) !=0) return 1;
		  else return 0;
	}
	if(counter == 4) return 1; //É válido apenas se os 4 bytes forem válidos.
 }

void decrypt(unsigned int *file, int size) {
	int i;

	for(i=0; i<size;i++) 
		//Se os bytes do inteiro não representarem caracteres válidos o inteiro é shiftado para a direita
		if(!isValid(file[i])) file[i] = file[i] >> 1;
	return;
}

void readS(unsigned int *file, int size) {
	char c; 
	int counter = 0; 
	char *string;
	string = (char *)&file[size];
	
	do {
		c = fgetc(stdin);
		//O realloc será usado com file pois deve-se ultilizar a mesma região da memória
		//para onde os dados do disco foram copiados
		file = (unsigned int *)realloc(file, sizeof(int)*size + sizeof(char)*(counter+1));
		string[counter++] = c;
	} while (c != ENTER);
	string[counter-1] = '\0';

	return;
}

void occurrence(unsigned int *file, int size) {
	int i, j, len;
	int counter;
	char *word, *text;
	
	text = (char *)&file[0];//Aponta a partir do primeiro byte de char (onde está a mensagem)
	word = (char *)&file[size];//Aponta a partir da célula onde começa a string que será buscada
	len = strlen(text) - strlen(word);
	counter = 0;//Contador de ocorrências.

	for (i = 0; i <= len; i++) {
		for (j = 0; j < strlen(word) && word[j]==text[i+j];j++);
		if (j == strlen(word)) counter++;
	}
	printf("%d\n", counter);//Imprime o total de ocorrências
	return;
}

void chooseFunction(unsigned int *file, int size, char *name) {
	int op;
	scanf("%d", &op);
	
	switch(op) {

		case 1: //Mapeamento de dígitos.
			map(file, size, name);
			break;
		case 2: //Descriptografia.
			decrypt(file, size);
			printf("%s\n", (char *)file); //Imprime a mensagem descriptografada.
			break;
		case 3: //Contagem de ocorrências.
			scanf("%*c");
			decrypt(file, size);
			readS(file, size); //recebe a string a ser procurada
			occurrence(file, size); //buscará a quantidade de ocorrências de string na mensagem
			break;
		default: //Caso o operador digitado não seja 1, 2 ou 3.
			("operador desconhecido\n");
	}
}

int main(int argc, char *argv[]) {

	int i, tamanho;
	unsigned int *file = NULL;
	char *nome;
	FILE *fp_input;
	
	nome = readLine(); //recebe o nome do arquivo
	fp_input = fopen(nome, "rb");//abre o arquivo com o nome informado
										 //usa-se "rb" pois o arquivo está salvo como binário(.bin)
		if(fp_input == NULL) noFile(nome, fp_input);//executa a função caso o arquivo esteja vazio

	tamanho = size(fp_input); //recebe o tamanho, em bytes, do arquivo
	file = alocateFile(tamanho, fp_input); //recebe o conteúdo do arquivo
	reverseVec(file, tamanho); //Função para desinverter o vetor

	chooseFunction(file, tamanho, nome); //Função para o usuário escolher a operação a ser executada

	//É liberado tudo que foi salvo na Heap.
	free(file);
	free(nome);

	return 0;
}