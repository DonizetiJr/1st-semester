#ifndef _CRYPT_H_
#define _CRYPT_H_

typedef unsigned char byte;

byte *crypt(byte *, int, double **, int, int);
byte *decrypt(byte *, int, double **, int, int);

#endif
