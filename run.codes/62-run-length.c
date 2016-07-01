#include <stdlib.h>
#include <stdio.h>

#define ENTER 10

char *readLine() {
   int counter = 0;
   char c;
   char *string = NULL;

   do {
      c = fgetc(stdin);

      string = (char *)realloc(string, sizeof(char)*(counter+1));
      string[counter++] = c;

   } while (c != ENTER);
   string[counter-1] = '\0';

   return string;
}

void image_data(FILE *stream, int *col, int *row, int *grey_scale) {
   fseek(stream, 2, SEEK_SET);

   fscanf(stream, "%d", col);
   fscanf(stream, "%d", row);
   fscanf(stream, "%d", grey_scale);

   return;
}

void compact(int n, int counter, int cpt) {
   int i;

   if(!cpt)
      for(i = 0; i < counter; i++) printf("%d ", n);
   else
      printf("@ %d %d ", n, counter);

   return;
}

void run_length(FILE *stream, int col, int row, int grey_scale){
   int aux, prev, i, j, counter;

   printf("P8\n");
   printf("%d %d\n", col, row);
   printf("%d\n", grey_scale);

   for(i = 0; i < row; i++) {
      counter = 1;
      fscanf(stream, "%d", &aux);
      prev = aux;
      for(j = 1; j < col; j++) {
         fscanf(stream, "%d", &aux);
         if(aux == prev) {
            counter++;
         } else if(counter < 3) {
            compact(prev, counter, 0);
            counter = 1;
         } else {
            compact(prev, counter, 1);
            counter = 1;
         }
         prev = aux;
      }
      if(counter > 3) compact(aux, counter, 1);
      else if(counter == 1) printf("%d", aux);
      printf("\n");
   }
   return;
}

int main(int argc, char const *argv[]) {
   int col, row, grey_scale;
   char *file_name;
   FILE *fp;

   file_name = readLine();
   fp = fopen(file_name, "r");
   image_data(fp, &col, &row, &grey_scale);
   run_length(fp, col, row, grey_scale);

   fclose(fp);
   free(file_name);
   return 0;
}
