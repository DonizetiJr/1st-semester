#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Person {
	int code;
	char *name;
	int age;
};

typedef struct Person PERSON;

int main(int argc, char *argv[]) {
	PERSON *person;

	person = (PERSON *) malloc(sizeof(PERSON) * 2);

	printf("Sizeof = %d\n\n", sizeof(PERSON));

	printf("Endereco de person = %p\n", person);
	person->code = 0;
	person->name = (char *) malloc(sizeof(char) * 10);
	strcpy(person->name, "A");
	person->age = 1;

	printf("Endereco de (person+1) = %p\n\n", (person+1));
	(person+1)->code = 1;
	(person+1)->name = (char *) malloc(sizeof(char) * 10);
	strcpy((person+1)->name, "B");
	(person+1)->age = 2;

	printf("Code %d Name %s Age %d\n\n", 
			person->code, person->name, person->age);
	printf("Code %d Name %s Age %d\n", 
			(person+1)->code, (person+1)->name, (person+1)->age);

	free(person->name);
	free((person+1)->name);
	free(person);

	return 0;
}
