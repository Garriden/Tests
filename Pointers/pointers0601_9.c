/*
25, 36
ptr holds the address of a variable A and ptr1 holds the address of a variable B.
The value of A is 25 and B is 36.
*/

#include<stdio.h>

int main(){
	int a = 25, b;
	int *ptr, *ptr1;
	ptr = &a;
	ptr1 = &b;
	b = 36;
	printf("%d %d",*ptr, *ptr1);
	return 0;
}
