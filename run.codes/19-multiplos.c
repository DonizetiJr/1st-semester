#include <stdio.h>

int main(int argc, char argv[]){

	int n, i, j, c, counter;
	scanf("%d%d%d", &n, &i, &j);

	c = 0;
	counter = 0;
	
	for(c = 0; counter < n; c++) {
		if(c%i == 0 || c%j == 0) {
		printf("%d\n", c);
		counter++;
		}
	}


	return 0;
}