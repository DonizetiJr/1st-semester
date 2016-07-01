/*
 		-------------
		|           |
 		-------------
		|           |
 		-------------
		|           |
 		-------------
		|           |
 		-------------
		|           |
 		-------------
		|           |
 		-------------
		|           |  int *ponteiro;
		|           |  ponteiro = string;
		|           |  printf("%d\n", ponteiro[0]);
		|     X     |  printf("%d\n", ponteiro[1]);
		|           |
		|           |
		|           |
		|           |
 		-------------
		|           | int i
		|           |
		|           |
		|           |
 		-------------
	X	| 01100001  |  char string[12]		'a' = 97
 		-------------
		| 01100010  |				'b' = 98
 		-------------
		| 01100011  |				'c' = 99
 		-------------
		| 01100100  |				'd' = 100
 		-------------
		| 01100001  |				'a'
 		-------------
		| 01100010  |				'b'
 		-------------
		| 01100011  |				'c'
 		-------------
		| 00000000  |				'\0' = 0
 		-------------
		|           |
 		-------------
		|           |
 		-------------
		|           |
 		-------------
		|           |  FIM DA STACK
 		-------------

 */

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {

	// STACK
	char string[12]; // char -> 1 byte -> 12 * 1 = 12 bytes
	int i; // 4 bytes
	int *ponteiro;

	printf("Digite uma cadeia de caracteres: ");
	scanf("%s", string);

	printf("String: %s\n\n", string);

	// strlen = string length
	for (i = 0; i < strlen(string); i++) {
		printf("%c\t%d\n", string[i], string[i]);
	}

	ponteiro = (int *) &string; // cast casting

	printf("\n1684234849 == ??? %d\n", ponteiro[0]); // 1684234849
	printf("6513249 == ??? %d\n", ponteiro[1]); // 6513249

	return 0;
}










