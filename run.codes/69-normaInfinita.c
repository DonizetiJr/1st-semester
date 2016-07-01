#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define ENTER 10

char *readLine() {
   char c;
   int counter = 0;
   char *string = NULL;

   do {
      c = fgetc(stdin);

      string = (char *)realloc(string, sizeof(char)*(counter+1));
      string[counter++] = c;
   } while (c != ENTER);

   string[counter-1] = '\0';

   return string;
}

int mat_length(FILE *stream) {
   int counter;
   double aux;

   while(EOF != fscanf(stream, "%lf", &aux))
      counter++;
   fseek(stream, 0, SEEK_SET);

   return sqrt(counter);
}

double **write_matrix(FILE *stream, int len) {
   int i, j;
   double **matrix;

   matrix = (double **)malloc(sizeof(double *)*len);

   for(i = 0; i < len; i++) {
      matrix[i] = (double *)malloc(sizeof(double)*len);
      for(j = 0; j < len; j++) {
         fscanf(stream, "%lf", &matrix[i][j]);
      }
   }
   return matrix;
}

double verify_norma(double *num, int len) {
   int i;
   double max = 0;

   for(i = 0; i < len; i++)
      if(num[i] > max) max = num[i];

   return max;
}

void norma(double **matrix, int len) {
   int i, j;
   double norma;
   double *sum;

   sum = (double *)calloc(len, sizeof(double));
   for(i = 0; i < len; i++) {
      for(j = 0; j < len; j++)
         sum[i] += matrix[i][j];
   }
   norma = verify_norma(sum, len);
   printf("%.4lf\n", norma);

   free(sum);

   return;
}

double **matrix_sum(double **mat1, double **mat2, int len) {
   int i, j;
   double **new_matrix;

   new_matrix = (double **)malloc(sizeof(double *)*len);
   for(i = 0; i < len; i++) {
      new_matrix[i] = (double *)malloc(sizeof(double)*len);
      for(j = 0; j < len; j++) {
         new_matrix[i][j] = mat1[i][j]+mat2[i][j];
         printf("%.4lf ", new_matrix[i][j]);
      }
      printf("\n");
   }
   return new_matrix;
}

void freePointers(double **p, int len) {
	int i;
	for(i = 0; i < len; i++)
		free(p[i]);
	free(p);
}

int main(int argc, char *argv[]) {
   int len;
   char *mat_file1, *mat_file2;
   double **mat1, **mat2, **result_mat;
   FILE *fp1, *fp2;

   mat_file1 = readLine();
   mat_file2 = readLine();

   fp1 = fopen(mat_file1, "r");
   fp2 = fopen(mat_file2, "r");

   len = mat_length(fp1);
   mat1 = write_matrix(fp1, len);
   norma(mat1, len);

   mat2 = write_matrix(fp2, len);
   norma(mat2, len);

   result_mat = matrix_sum(mat1, mat2, len);
   norma(result_mat, len);

   fclose(fp1);
   fclose(fp2);
   free(mat_file1);
   free(mat_file2);
   freePointers(mat1, len);
   freePointers(mat2, len);
   freePointers(result_mat, len);

   return 0;
}
