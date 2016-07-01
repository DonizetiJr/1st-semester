#include <stdlib.h>
#include <stdio.h>

#define ENTER 10

char *readLine() {
	char c, counter = 0;
	char *str = NULL;

	do {
		c = fgetc(stdin);

		str = (char *)realloc(str, sizeof(char) * (counter+1));
		str[counter++] = c;
	} while (c != ENTER);

	str[counter-1] = '\0';

	return str;

}

int **pgm2matrix(FILE *fp, int *col, int *row, int *grey_scale) {
   int i, j;
   int **matrix;
   char magic_number[2];

   fscanf(fp, "%s", magic_number);
   fscanf(fp, "%d %d %d", col, row, grey_scale);

   matrix = (int **)malloc(sizeof(int *)*(*row));
   for (i = 0; i < *row; i++) {
      matrix[i] = (int *)malloc(sizeof(int *)*(*col));

      for(j = 0; j < *col; j++) fscanf(fp, "%d", &matrix[i][j]);
   }
   fclose(fp);
   return matrix;
}

void floodfill(int **image, int pixel, int x, int y, int row,
               int col, int grey_level) {
   image[x][y] = grey_level;

   if(y-1 >= 0 && image[x][y-1] == pixel)
      floodfill(image, pixel, x, y-1, row, col, grey_level);
   if(x-1 >= 0 && image[x-1][y] == pixel)
      floodfill(image, pixel, x-1, y, row, col, grey_level);
   if(x+1 < row && image[x+1][y] == pixel)
      floodfill(image, pixel, x+1, y, row, col, grey_level);
   if(y+1 < col && image[x][y+1] == pixel)
      floodfill(image, pixel, x, y+1, row, col, grey_level);
}

void generate_image(char *file_name, int **image, int row,
                     int col, int grey_scale) {
   int i, j;
   FILE *output_file;

   output_file = fopen(file_name, "w");
   fprintf(output_file, "%s\n", "P2");
   fprintf(output_file, "%d %d\n", col, row);
   fprintf(output_file, "%d\n", grey_scale);

   for(i = 0; i < row; i++) {
      for(j = 0; j < col; j++)
         fprintf(output_file, "%d\n", image[i][j]);
      fprintf(output_file, "\n");
   }
}

void freeMatrix(int **matrix, int n) {
   int i;
   for (i = 0; i < n; i++) free(matrix[i]);
   free(matrix);
}

int main(int argc, char *argv[]) {
   int row, col, grey_scale, x, y, grey_level;
   int **image;
   char *file_in, *file_out;
   FILE *fp;

   file_in = readLine();
   file_out = readLine();

   scanf("%d %d", &x, &y);
   scanf("%d", &grey_level);

   fp = fopen(file_in, "r");
   image = pgm2matrix(fp, &row, &col, &grey_scale);
   floodfill(image, image[x][y], x, y, row, col, grey_level);
   generate_image(file_out, image, row, col, grey_scale);

   free(file_in);
   free(file_out);

   freeMatrix(image, col);

   return 0;
}
