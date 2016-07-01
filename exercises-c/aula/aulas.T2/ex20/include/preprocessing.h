#ifndef _PREPROCESSING_H_
#define _PREPROCESSING_H_

#include <utils.h>

char *preprocessing(byte *, long);
char **words(char *, int *);
int normalize(char **, int);
char **unique(char **, int, int *);
char *vec2char(double *, int);
double *char2vec(char *, int);
double **vectors(char **, int, int);

#endif
