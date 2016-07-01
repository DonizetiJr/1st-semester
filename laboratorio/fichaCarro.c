#include <stdlib.h>
#include <stdio.h>

#define ENTER 10

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

float calcula_consumo(float distancia_percorrida, float litros_consumidos) {

}

float readValue(FILE *fp) {
	float c; 
	float distancia, litros, consumo;
	int counter = 0; 

	fscanf("%f", &distancia);
	fseek(fp, 1, SEEK_CUR);
	fscanf("%f", &litros);

	consumo = calcula_consumo(distancia, litros);
	return consumo;
}

char *le_arquivo(char *nome_arquivo, int *n, float **consumo) {
	int i, counter;
	char *modelo_carro = NULL;
	FILE *fp;
	fp = fopen(nome_arquivo, "r");

	counter = 0;
	i = 0; 
	do {
		modelo_carro = (char *)realloc(modelo_carro, sizeof(char)*(counter+1));
		fscanf(fp,"%c", &modelo_carro[i++]);
	}while(modelo_carro[i-1] != ENTER);
	modelo_carro[i] = '\0'; 

	*consumo = NULL;
	while(!feof) {
		fscanf(fp,"%d", *n);
		fseek(fp, 1, SEEK_CUR);
		consumo = (int *)realloc(consumo, sizeof(int)*(*n));
		consumo[(*n)-1] = readValue(fp); 
	}

	return modelo_carro;
}

/*
float calcular_media(float *consumo_km, int n);

float calcular_desvio_padrao(float *consumo_km, float media, int n);

struct Resultado *calcular_estatisticas(float *consumo_km, int n);

void imprime_resultado(struct Resultado *resultado, char *modelo_carro);

void desaloca_vetor_consumo(float *consumo_km);
*/

int main(int argc, char *argv[]) {
	int n;
	char *modelo;
	char *nome_arquivo;
	float *consumo_km;
	FILE *fp;

	nome_arquivo = readLine();
	modelo = le_arquivo(nome_arquivo, &consumo_km);
	printf("%s", modelo);



	free(nome_arquivo);
	free(modelo);

	return 0;
}