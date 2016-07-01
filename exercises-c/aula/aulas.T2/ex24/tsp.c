// Travelling Sales person

// Computers and Intractability
// Garey & Johnson
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef enum {
	FALSE,
	TRUE
} boolean;

void produce_solution_iteractive() {
	int i, j, k;

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			for (k = 0; k < 3; k++) {
				if (i != j && i != k && j != k) {
					printf("%d %d %d\n", i, j, k);
				}
			}
		}
	}
}

void print_solution(int *solution, int ncities) {
	int i;
	for (i = 0; i < ncities; i++) printf("%d ", solution[i]);
	printf("\n");
}

boolean isValid(int *solution, int ncities) {
	int i;
	int *freq = (int *) calloc(ncities, sizeof(int));

	// solution
	// 1 1 1
	//
	// freq
	// 0 3 0 
	for (i = 0; i < ncities; i++) {
		if (++freq[solution[i]] > 1) {
			free(freq);
			return FALSE;
		}
	}

	free(freq);
	return TRUE;
}

// produce_solution_iteractive()
void produce_solution_recursive(int *solution, int level, int ncities) {
	int i;

	if (level == 0) {
		if (isValid(solution, ncities)) {
			print_solution(solution, ncities);
		}
		return; // caso base
	}

	for (i = 0; i < ncities; i++) {
		solution[ncities - level] = i;
		//printf("%d\n", i);
		produce_solution_recursive(solution, level-1, ncities);
	}
}

enum {
	PROGNAME,
	NCITIES,
	NARGS
};

int main(int argc, char *argv[]) {

	if (argc != NARGS) {
		printf("usage: %s ncities\n", argv[PROGNAME]);
		return -1;
	}

	clock_t before, after;
	int ncities = atoi(argv[NCITIES]);
	int *solution = (int *) malloc(sizeof(int)*ncities);
	double secs;

	before = clock();
	produce_solution_recursive(solution, ncities, ncities);
	after = clock();

	secs = (after - before) / (CLOCKS_PER_SEC * 1.0);
	fprintf(stderr, "%lf", secs);

	free(solution);

	return 0;
}















