#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

typedef struct {
	int code;
	char *name;
	int age;
} PERSON;

PERSON *create_person_vector(int n) {
	int i, j;
	PERSON *vector = (PERSON *) malloc(sizeof(PERSON) * n); // 24 bytes * n

	srand(time(NULL));

	for (i = 0; i < n; i++) {
		vector[i].code = rand();
		vector[i].name = (char *) malloc(sizeof(char) * 5);

		for (j = 0; j < 4; j++) {
			vector[i].name[j] = 65 + (rand() % 27);
		}
		vector[i].name[j] = '\0';

		vector[i].age = rand();
	}

	return vector;
}

void free_person_vector(PERSON *vector, int n) {
	int i;

	for (i = 0; i < n; i++) {
		free(vector[i].name);
	}

	free(vector);
}

void write(FILE *stream, PERSON *vector, int n) {
	int i;

	for (i = 0; i < n; i++) {
		fprintf(stream, "Code: %d Name: %s Age: %d\n",
				vector[i].code,
				vector[i].name,
				vector[i].age);
	}
}

enum {
	PROGNAME,
	NUMBER,
	FILENAME,
	NARGS
};

int main(int argc, char *argv[]) {

	if (argc != NARGS) {
		printf("usage: %s number filename\n", argv[PROGNAME]);
		return -1;
	}

	int number = atoi(argv[NUMBER]);
	FILE *fp = fopen(argv[FILENAME], "w+");

	if (fp == NULL) {
		printf("Could not open file.\n");
		return -2;
	}

	PERSON *vector = create_person_vector(number);
	write(fp, vector, number);
	free_person_vector(vector, number);

	fclose(fp);

	return 0;
}
