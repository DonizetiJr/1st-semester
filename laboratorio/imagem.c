#include <stdlib.h>
#include <stdio.h>


int main(int argc, char *argv[]) {
	
	int col, row, grey, i, j, tamanho;
	char *hist;
	int *counter;
	char magcnumber[10];
	char name[100];
	FILE *fp;
	
	scanf("%s", name);
	fp = fopen(name, "rb");

	fscanf(fp, "%s", magcnumber);
	fscanf(fp,"%d", &col);
	fscanf(fp,"%d", &row);
	fscanf(fp,"%d", &grey);

	fseek( fp, 1, SEEK_CUR);

	hist = (char *)malloc(sizeof(char)*(col));
	counter = (int *)calloc(grey+1, sizeof(int));
	for(i=0;i<row;i++) {
		fread(hist, grey > 255 ? 2 : 1, col, fp); 
		for(j=0;j<col;j++) {
			counter[(unsigned char)hist[j]]++;
		}
	}
	for(i=0;i<grey+1;i++)
		printf("%d | %u\n", i, counter[i]);

	fclose(fp);
	free(hist);
	free(counter);

	return 0;
}