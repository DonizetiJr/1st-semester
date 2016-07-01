#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *readLine() {
	char c, enter; 
	char *string = NULL; 
	int counter = 0; 
	
	do {
		scanf("%c", &c);
		scanf("%c", &enter);
		
		string=(char *)realloc(string,sizeof(char)*(counter+1));
		string[counter++] = c;
	} while (c != 'x'); 
	string[counter] = '\0';
	
	return string;
}


int main(int argc, char *argv[]) {
	char i, j, temp;
	char *list;
	int *list_int;
	list = readLine();

	for(i = 0; i < strlen(list)-1; i++) {
		for(j = i; j < strlen(list); j++) {
			if (list[i] > list[j]) {
   			temp = list[i];
   			list[i] = list[j];
  				list[j] = temp;
  			}
   	}
  	}
	list_int = (int *)&list[0];
	
	for(i = 0; i < strlen(list)/4; i++) 
		printf("%d\n", list_int[i]);

	free(list_int);

	return 0;
}