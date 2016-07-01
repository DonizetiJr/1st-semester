#include <stdlib.h>
#include <stdio.h>

#define ENTER 10

enum Data
{
	day,
	month,
	year,
	hour,
	minutes,
	seconds
};

char *readLine() {
	char c; 
	char *string = NULL; 
	int counter = 0; 

	do {
		c = fgetc(stdin);
		
		string=(char *)realloc(string,sizeof(char)*(counter+1));
		string[counter++] = c;
	} while (c != ENTER);
	string[counter-1] = '\0';
	
	return string;
}

int *receivaData() {
	int i;
	int *num;

	num = (int *)malloc(sizeof(int)*6);

	for(i = 0; i < 6; i++) 
		scanf("%d", &num[i]);

	return num;
}

void printAgenda(int **data, char **apoint, int n) {
	int i;
	for(i = 0; i < n; i++) {
		printf("%02d/%02d/%04d - %02d:%02d:%02d\n", data[i][day], 
								data[i][month], data[i][year], data[i][hour], 
								data[i][minutes], data[i][seconds]);
		printf("%s\n", apoint[i]);
	}
}

void freeAgenda(int **data, char **apoint, int n) {
	int i;
	for(i = 0; i < n; i++) {
		free(data[i]);
		free(apoint[i]);
	}
	free(data);
	free(apoint);
}

void receiveAgenda(int n) {
	int i;
	int **data;
	char **apoint;

	apoint = (char **)malloc(sizeof(char *)*n);
	data = (int **)malloc(sizeof(int *)*n);

	for(i = 0; i < n; i++) {
		data[i] = receivaData(data[i]);
		scanf("%*c");
		apoint[i] = readLine();
	}
	printAgenda(data, apoint, n);

	freeAgenda(data, apoint, n);
}

int main(int argc, char *argv[]) {

	int n;
	scanf("%d", &n);

	receiveAgenda(n);


	return 0;
} 