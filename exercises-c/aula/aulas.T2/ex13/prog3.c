#include <stdio.h>

void create_vector(/*int array[5]*/ int *array) {
	int i;

	printf("sizeof array??? => %d\n", sizeof(array));

	for (i = 0; i < 5; i++) {
		printf("%d\n", array[i]);
	}
}

int main(int argc, char *argv[]) {
	int i;
	int array[5]; // 5 * 4 = 20 bytes

	printf("Endereco i => %p\n", &i);
	printf("Endereco array => %p\t%p (tamanho do array %d)\n", 
			array, &array, sizeof(array));

	for (i = 0; i < 5; i++) {
		scanf("%d", &array[i]);
	}

	create_vector(array);

	return 0;
}





