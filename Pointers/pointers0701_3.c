/*
sizeof void is 1 and the sizeof void pointer is 4
*/
#include<stdio.h>

int main()
{
	printf("%d", sizeof(void *));
	return 0;
}
