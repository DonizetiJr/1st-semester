#include <stdio.h>

int main(int argc, char *argv[]) {

	int n, j, m, i;
	scanf("%d%d%d", &n, &j, &m);

	int counter = 1;
	for(i=0; counter<=n; i++) {
		if(i%m == j%m) {
			printf("%d\n", i);
			counter++;
		}
	}


	return 0;
}