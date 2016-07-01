#include <stdio.h>

void seq(int n,int m, int ultimo) {
		if(n<=m){
		int i;
		for(i=0; i<n; i++){
			printf("%d ", ultimo);
			ultimo +=2;
		}
	printf("\n");
	n++;
	seq(n,m,ultimo);
		}
	}

int main (int argc, char *argv[]) {

	int m;
	scanf("%d", &m);

	seq(1, m, 1);


return 0;
}