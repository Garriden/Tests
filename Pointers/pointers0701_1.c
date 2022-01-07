/*
C from 2braces.com
*/
#include<stdio.h>

int main()
{
	char *ptr;
	char string[] = "learn C from 2braces.com";
	ptr = string;
	ptr += 6;
	printf("%s",ptr);
	return 0;
}
