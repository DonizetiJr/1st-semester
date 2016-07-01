#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define X 0
#define Y 1

typedef enum {
	FALSE,
	TRUE
} boolean;

double **receive_paths(int ncities) {
	int i;
	double **cities = (double **)malloc(sizeof(double *)*ncities);

	for(i = 0; i < ncities; i++) {
		cities[i] = (double *)malloc(sizeof(double)*2);
		scanf("%lf %lf", &cities[i][X], &cities[i][Y]);
	}
	return cities;
}

double fat(int n) {
	if(n != 0) return n*fat(n-1);
	else return 1;
}

int **allocate_paths(int n) {
	int i;
	int **paths;

	paths = (int **)malloc(sizeof(int)*fat(n));
	for(i = 0; i < n; i++)
		paths[i] = (int *) malloc(sizeof(int)*n);
		return paths;
}

boolean isValid(int *solution, int ncities) {
	int i;
	int *freq = (int *) calloc(ncities, sizeof(int));

	for (i = 0; i < ncities; i++) {
		if (++freq[solution[i]] > 1) {
			free(freq);
			return FALSE;
		}
	}
	free(freq);
	return TRUE;
}

void possible_ways(double **cities, int num, int **paths, int level, int ncities) {
	int i, j;
	boolean run;

	if (level == 0) {
		if (isValid(paths[num], ncities))
			num++;
		return; // caso base
	}

	for (i = 0; i < ncities; i++) {
		paths[num][ncities - level] = i;

		run = TRUE;
		for (j = 0; j < ncities-level; j++) {
			if (paths[num][j] == i) run = FALSE;
		}
		if (run) {
			possible_ways(cities, num, paths, level-1, ncities);
		}
	}
}

void distance(double **cities, int **vector, int n) {
	int i, j;
	double x1, result = 0;

	for(j = 0; j < n; j++) {
		for (i = 0; i < n-1; i++) {
			printf("%d\n", vector[j][i]);
			x1 = (cities[vector[j][i]][Y] - cities[vector[j][i]][X]) * (cities[vector[j][i]][Y] - cities[vector[j][i]][X]) +
					(cities[vector[j][i+1]][Y] - cities[vector[j][i+1]][X]) * (cities[vector[j][i+1]][Y] - cities[vector[j][i+1]][X]);

			result += sqrt(x1);
		}
		x1 = (cities[vector[j][n-1]][Y] - cities[vector[j][n-1]][X]) * (cities[vector[j][n-1]][Y] - cities[vector[j][n-1]][X]) +
				(cities[vector[j][0]][Y] - cities[vector[j][0]][X]) * (cities[vector[j][0]][Y] - cities[vector[j][0]][X]);

		result += sqrt(x1);

		printf("%lf\n", result);
	}
	return;
}

int main(int argc, char *argv[]) {

	int n, i;
	int **paths;
	double **cities;
	scanf("%d", &n);

	cities = receive_paths(n);
	paths = allocate_paths(n);
	possible_ways(cities, 0, paths, n, n);
	distance(cities, paths, n);

	free(paths);
	for(i = 0; i < n; i++) free(cities[i]);
	free(cities);

	return 0;
}
