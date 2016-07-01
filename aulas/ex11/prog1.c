#include <stdio.h>

int main(int argc, char *argv[]) {
	FILE *fp_input; // 8 bytes STACK
	FILE *fp_output; // 8 bytes STACK
	char c; // 1 byte STACK

	// r  = leitura apenas, cursor posicionado no inicio do arquivo
	// w  = truncate (apagado), escrita e cursor posicionado no inicio
	// r+ = leitura e escrita, cursor posicionado no inicio do arquivo
	// w+ = truncate (apagado), leitura, escrita e cursor posicionado no inicio
	// a  = append (escrita a partir do final), cursor posicionado no final
	// a+ = append (escrita a partri do final), leitura,
	// 		cursor será posicionado no final do arquivo
	fp_input = fopen("arquivo", "r");
	printf("fp_input = %p\n", fp_input);
	if (fp_input == NULL) {
		printf("Unable to open input file.\n");
		return 1;
	}

	fp_output = fopen("saida", "w");
	printf("fp_output = %p\n", fp_output);
	if (fp_output == NULL) {
		printf("You do not have the correct permission.\n");
		return 1;
	}

	// feof(fp_input); 0: não for fim; 1: se for fim de arquivo
	// eof end-of-file
	while (!feof(fp_input)) {
		c = fgetc(fp_input);

		printf("%c\t%d\n", c, c);

		//if (!feof(fp_input)) {
			fputc(c, fp_output);
		//}
	}

	fclose(fp_input);
	fclose(fp_output);

	return 0;
}
