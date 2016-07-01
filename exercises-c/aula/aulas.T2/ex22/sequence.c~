#include <stdio.h>

// 1, 3, 6, 10, 15, 21, 28, 36, 45, ...
//   2  3  4   5  6   7   8   9

// ITERATIVA
void sequence_triangular_iterativa(int n) {
	int i, term = 0;
	for (i = 1; i <= n; i++) {
		term += i;
		printf("%d\n", term);
	}
}

// RECURSIVA
void sequence_triangular_recursiva(int term, int i, int n) {
	if (i > n) return; // caso base
	printf("%d\n", term);
       	sequence_triangular_recursiva(term+i, i+1, n); // passo recursivo
}

int sum_pa(int n) {
	return n < 1 ? 0 : n + sum_pa(n-1);
}

void sequence_triangular_recursiva2(int n) {
	if (n < 1) return;
	int ret = sum_pa(n);
	printf("%d\n", ret);
	sequence_triangular_recursiva2(n-1);
}

int main(int argc, char *argv[]) {

	//sequence_triangular_recursiva(1, 2, 10);
	sequence_triangular_recursiva2(10);

	return 0;
}
