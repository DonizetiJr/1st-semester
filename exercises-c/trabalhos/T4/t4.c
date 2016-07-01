#include <stdlib.h>
#include <stdio.h>

#define ENTER 10

//Lê strings digitadas até o enter.
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

void noFile(char *name, FILE *stream) {
	//imprime a mensagem informando o usuário que não foi possível abrir o arquivo
	printf("Error opening file\n");
	//Como o programa será encerrado, fecha-se o arquivo e é liberado o que foi salvo na Heap
	fclose(stream);
	free(name);
		exit(-1); // encerra o programa
}

//Lê do arquivo a primeira linha que contém o tipo da imagem e
//ignorara, caso houver, comentários na imagem.
void jumpFileContent(FILE *stream, char delim ) {
	char c;
	do { //Lê até o enter.
		fscanf(stream, "%c", &c);
	} while(c != ENTER);

	fscanf(stream, "%c", &c);
	//Caso haja comentários, leŕa toda a linha.
	if(c == '#') jumpFileContent(stream, ENTER); 
	else fseek(stream, -1, SEEK_CUR);
}
//Lê as dimensões da imagem e seu valor máximo de cinza.
void imageDim(int *row, int *col, int *grey_scale, FILE *stream) {
	jumpFileContent(stream, ENTER); //Pulará as primeiras linhas
	fscanf(stream, "%d %d", col, row);
	fscanf(stream, "%d", grey_scale);
}
//Alocação dinâmica de uma imagem (matriz).
int **allocateNewImage(int col, int row) {
	int i;
	int **image;

	image = (int **)calloc(row, sizeof(int *));
	
	for(i = 0; i < row; i++)
		image[i] = (int *)calloc(col, sizeof(int));
	return image;
}
//Copia o conteúdo de uma matriz(imagem) para outra.
void createImage(FILE *image, int **new_image, int col, 
							int row) {
	int i, j, num;
	for(i = 0; i < row; i++) {
		for(j = 0; j < col; j++)
			fscanf(image, "%d", &new_image[i][j]);
	}
}

void toNegative(int **negative_image, int col, int row,
							int grey_scale) {
	int i, j;
	for(i = 0; i < row; i++) {
		for(j = 0; j < col; j++)
			//Transformação de negativos da imagem
			negative_image[i][j] = grey_scale - negative_image[i][j];
	}
}
//Imprime todos os pixels da imagem solicitada.
void printImage(int row, int col, int grey_scale, int **image) {
	int i, j;

	printf("P2\n");//Formato padrão de imagem PGM.
	printf("%d %d\n", col, row);
	printf("%d\n", grey_scale);

	for(i=0; i < row; i++) {
		for(j=0; j < col; j++)
			printf("%d ", image[i][j]); 
		printf("\n");
	}
}
//Libera da Heap ponteiros duplos.
void freePointers(int **p, int row) {
	int i;
	for(i = 0; i < row; i++)
		free(p[i]);
	free(p);
}
//Realizará o realce da imagem produzindo sua negativa.
void **negativeTransform(FILE *stream, int row, int col, int grey_scale) {
	int i, j;
	int **new;

	new = allocateNewImage(col, row);//Aloca uma nova imagem.
	createImage(stream, new, col, row);//Copia a imagem original para mantê-la.
	toNegative(new, col, row, grey_scale);//Produz o negativo.
	printImage(row, col, grey_scale, new);//Imprime o negativo.

	freePointers(new, row);//Libera da Heap a imagem criada.
}
//Lê o conteúdo da máscara.
double **readMask(FILE *stream, int *dim) {
	int i, j;
	double **mask;
	fscanf(stream, "%d", dim);

	mask = (double **)malloc(sizeof(double *)*(*dim));

	for(i = 0; i < *dim; i++) {
		mask[i] = (double *)malloc(sizeof(double)*(*dim));
		for(j = 0; j < *dim; j++) 
			fscanf(stream, "%lf", &mask[i][j]);	
	}
	return mask;
}
//Libera o conteúdo relacionado à máscara.
void freeMask(int mask_dim, double **mask, char *mask_file, FILE *fp) {
	int i;
	for(i = 0; i < mask_dim; i++) free(mask[i]);
	free(mask);
	free(mask_file);
	fclose(fp);
}

void maxMin(int **image, int *max, int *min, int row, int col) {
	int i, j;
	//Inicializadores:
	*max = 0;
	*min = image[0][0];
	//Indentificação dos valores máximos e mínimos:
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			if(image[i][j] > *max) *max = image[i][j];
			else if(image[i][j] < *min) *min = image[i][j];
		}
	}
}

void normalize(int **image, int row, int col, int grey_scale) {
	int gmax, gmin, i, j;
	//Recebe os valores máximos e mínimos da nova imagem.
	maxMin(image, &gmax, &gmin, row, col);
	//Cálculo da normalização:
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			image[i][j] = (grey_scale*(image[i][j]-gmin))/(gmax-gmin);
		}
	}
}

void maskMult(int row, int col, int **image, int **new_image,
					int mask_dim, double **mask) {
	int i, j, center, m, n, mm, nn, ii, jj;

	center = mask_dim/2;

	for(i=0; i < row; i++) {          	// linhas
		for(j=0; j < col; j++) {        // colunas
	   	for(m=0; m < mask_dim; m++) {// linhas da máscara
	      	mm = mask_dim - 1 - m;   // inversão das linhas

	      	for(n=0; n < mask_dim; n++) {// colunas da máscara
	            // inversão das colunas
					nn = mask_dim - 1 - n;
	            // Índice para checar bordas:
	            ii = i + (m - center);
	            jj = j + (n - center);
					// Ignora índices que estariam além da imagem.
	            if(ii >= 0 && ii < row && jj >= 0 && jj < col)
	               new_image[i][j] += image[ii][jj] * mask[mm][nn];
	         }
	      }
	 	}
	}
}

int **convolution(FILE *stream, double **mask, int row,
						int  col, int grey_scale, int mask_dim) {
	int **image, **new_image;

	image = allocateNewImage(col, row);
	createImage(stream, image, col, row);
	new_image = allocateNewImage(col, row);

	maskMult(row, col, image, new_image, mask_dim, mask);

	//Normalizará os pixels da imagem com a máscara já aplicada
	normalize(new_image, row, col, grey_scale);

	return new_image;
}

void operations(int op, FILE *stream, int row, int col, int grey_scale){
	int mask_dim;
	int **conv_image;
	double **mask;
	char *mask_file;
	FILE *fp;

	switch(op) {
		case 1: //Produção do negativo.
			negativeTransform(stream, row, col, grey_scale);
			break;
		
		case 2: //Filtragem Espacial.
			mask_file = readLine(); //Lê o nome do arquivo de máscara.
			fp = fopen(mask_file, "r");
			if(!fp) noFile(mask_file, fp);

			mask = readMask(fp, &mask_dim);//Armazena o seu conteúdo.
			//Recebe a imagem já com a filtragem espacial
			conv_image = convolution(stream, mask, row, col, grey_scale, mask_dim);
			//Libera o conteúdo relacionado com a máscara.
			freeMask(mask_dim, mask, mask_file, fp);
			printImage(row, col, grey_scale, conv_image);
			break;
		
		default:
			//Caso não seja digitado nenhum operador esperado
			printf("Unknown Operator.\n");
			break;
	}
}

int main(int argc, char *argv[]) {
	int op, row, col, grey_scale;
	char *image_file;
	FILE *fp;

	scanf("%d\n", &op); //Recebe a operação desejada.
	image_file = readLine(); //Lê o nome do arquivo.
	
	fp = fopen(image_file, "r");
		//executa a função caso o arquivo esteja vazio:
		if(!fp) noFile(image_file, fp);
	imageDim(&row, &col, &grey_scale, fp); //Recebrá as dimensões.
	operations(op, fp, row, col, grey_scale);//Executa a operação desejada.

	free(image_file);
	fclose(fp);

	return 0;
}