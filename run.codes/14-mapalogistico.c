#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {

	double x, r;
	int k,t;
	scanf("%lf %lf %d", &x, &r, &k);

	for(t = 1; t <= k; t++){
		x = x*r*(1-x);
		printf("%d %lf\n", t, x);
	}



	return 0;
}