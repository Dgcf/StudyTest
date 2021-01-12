#include <stdio.h>

extern char __executable_start[];
extern char etext[], _etext[], __etext[];
extern char edata[], _edata[];
extern char end[], _end[];

int main()
{
    printf("%X\n", __executable_start);
	printf("Text: %X, %X, %X\n", etext, _etext, __etext);
	printf("Data: %X, %X\n", edata, _edata);
	printf("End: %X, %X\n", end, _end);
	return 0;
}