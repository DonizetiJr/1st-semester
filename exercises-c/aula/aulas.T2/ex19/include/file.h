#ifndef _FILE_H_
#define _FILE_H_

#include <crypt.h>

byte *readFullFile(char *, long *);
void writeFullFile(char *, byte *, long);

#endif
