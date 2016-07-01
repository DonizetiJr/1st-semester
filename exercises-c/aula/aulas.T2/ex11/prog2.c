#include <stdio.h>

enum {
	PROGNAME,   // 0
	INPUTFILE,  // 1
	OUTPUTFILE, // 2
	NARGS       // 3
};

int main(int argc, char *argv[]) {
	FILE *fp_input; // 8 bytes STACK
	FILE *fp_output; // 8 bytes STACK
	double v3; // 8 bytes
	char v2[255]; // 255 bytes na STACK!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	int v1; // 4 bytes

	// argv[0] -> nome do programa
	// argv[1] -> primeiro parametro util (nome do arq de entrada)
	// argv[2] -> segundo parametro util (nome do arq de saida)

	if (argc != NARGS) {
		printf("usage: %s input_filename output_filename\n",argv[PROGNAME]);
		return 1;
	}

	fp_input = fopen(argv[INPUTFILE], "r");
	if (fp_input == NULL) {
		printf("Unable to open input file.\n");
		return 1;
	}

	fp_output = fopen(argv[OUTPUTFILE], "w");
	if (fp_output == NULL) {
		printf("You do not have the correct permission.\n");
		return 1;
	}

	while (!feof(fp_input)) {
		// fprintf fscanf
		fscanf(fp_input, "%d", &v1);
		fscanf(fp_input, "%s", v2);
		fscanf(fp_input, "%lf", &v3);

		if (!feof(fp_input)) {
			fprintf(fp_output, 
				"Id: %d\tNome: %s\tSalario: %lf\n", v1, v2, v3);
		}
	}

	fclose(fp_input);
	fclose(fp_output);

	return 0;
}












