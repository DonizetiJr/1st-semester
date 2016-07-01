
// aritmética de ponteiros

#include <stdio.h>
#include <string.h>

int minha_strlen_1(char *string) {
	int i = 0;
	while (string[i] != '\0') i++;
	return i;
}

int minha_strlen_2(char *string) {
	int i = 0;
	char *ptr = string; // recebendo o endereço de string

	while (ptr[i] != '\0') {
		i++;
	}

	return i;
}

int minha_strlen_3(char *string) {
	int i = 0;
	char *ptr = string; // recebendo o endereço de string

	while (*ptr != '\0') {
		printf("%c (endereco do contido em ptr: %p)\n", *ptr, ptr);
		ptr = ptr + 1; // aritmética de ponteiros
		i++;
	}

	return i;
}

unsigned int my_strlen(char *s) {
	int len;

	while (*s != '\0') {
		s++; // soma de sizeof(char) para s
		len++;
	}

	return len;
}

int main(int argc, char *argv[]) {
	char string[] = "Nome qualquer...";

	printf("Nome: %s\n", string);
	printf("Length 1: %d\n", minha_strlen_1(string));
	printf("Length 2: %d\n", minha_strlen_2(string));

	minha_strlen_3(string);

	printf("Sizeof: %d\n\n", sizeof(string));

	return 0;
}






