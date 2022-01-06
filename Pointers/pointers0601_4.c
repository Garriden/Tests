/*
In pointer, address operator and Multiplication operator are always cancel each other.
Thus *&*ptr = *ptr.
*/

#include<stdio.h>
int main()
{
	char *ptr = "2braces.com";
	printf("%c\n",*&*ptr);
	return 0;
}
