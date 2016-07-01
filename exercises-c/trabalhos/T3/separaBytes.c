#include <stdio.h>

int main() {

int i;
	int x[3];
	x[0] = 12578329; // 0xBFEE19
	unsigned char *byte;
	// Convert to unsigned char* because a char is 1 byte in size.
  // That is guaranteed by the standard.
  byte = (unsigned char *)(&x[0]);
  printf("Byte %d = %u\n", 0, (unsigned)byte[0]);
  printf("Byte %d = %u\n", 1, (unsigned)byte[1]);
  printf("Byte %d = %u\n", 2, (unsigned)byte[2]);
  printf("Byte %d = %u\n", 3, (unsigned)byte[3]);

/*  int a = (x >> 24) & 0xff;  // high-order (leftmost) byte: bits 24-31
  int b = (x >> 16) & 0xff;  // next byte, counting from left: bits 16-23
  int c = (x >>  8) & 0xff;  // next byte, bits 8-15
  int d = x         & 0xff;  // low-order byte: bits 0-7

  printf("%d %d %d %d", a, b, c, d);
*/	
	return 0;
}