#include <stdio.h>

#define ENTER	10
#define sum(a,b) a+b
#define test(a,b) a > b ? a : b

int main(int argc, char *argv[]) {
	int x=1, y=2;

	printf("%d\n", ENTER);
	printf("%d\n", sum(x,y));
	printf("%d\n", test(x,y));

	return 0;
}
