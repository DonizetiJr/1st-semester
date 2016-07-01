#include <stdlib.h>
#include <stdio.h>


double *recebeNum(int n) {
	int i;
	double *numeros, num;
	numeros = (double *)malloc(sizeof(double)*n);

	for(i=0;i<n;i++) {
		scanf("%lf", &num);
		numeros[i] = num; 
	}
	return numeros;
}

void sort(double *nums, int n) {
	int i, j;
	double aux;
	
	for (i = 0; i < n-1; i++) {
		for (j = i+1; j < n; j++) {
			if (nums[i] > nums[j]) {
				aux = nums[j];
				nums[j] = nums[i];
				nums[i] = aux;
			}
		}
	}
	return;
}

void print(double *nums, int n) {
   int i;
   int counter =1;
   for(i=0;i<n;i++){
		if(nums[i] == nums[i+1]){
		 counter++;
		} else {
			printf("%.1lf %d\n", nums[i], counter);
			counter = 1;
		}	
	}
}

int main(int argc, char *argv[]) {

	int n, i;
	double *nums;
	scanf("%d", &n);

	nums = recebeNum(n);
	
	sort(nums, n);
	print(nums, n);

	free(nums);

	return 0;
}