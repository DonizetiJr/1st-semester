#include <stdio.h>

int main(int argc, char *argv[]) {
	FILE *fp = fopen("out2", "r");
	int i;

	fread(&i, sizeof(int), 1, fp);
	printf("inteiro: %d\n", i);

	fclose(fp);

	return 0;
}
