#include <stdio.h>

typedef union {
	unsigned char c;	// 1 byte
	unsigned char flag:1;	// 1 bit
	unsigned char flag2:3;	// 3 bits
} BOOLEAN;	// 

typedef union {
	unsigned char flag:1;	// 1 bit
} BIT;

int main(int argc, char *argv[]) {
	int i;
	BOOLEAN b;

	printf("Sizeof BIT = %d\n", sizeof(BIT));

	b.c = 0;
	//b.flag = 0;
	
	for (i = 0; i < 10; i++) {
		printf("Flag %d\n", b.flag);
		b.flag += 1;
	}

	b.flag += 1;
	printf("Union = %d\n", b.c);

	return 0;
}
