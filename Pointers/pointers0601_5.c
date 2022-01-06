/*
-1
Difference between any two variables of same data type are always one. Char ?
*/

#include<stdio.h>
#include<string.h>
int main(){
	char a = 30, b = 5;
	char *p = &a, *q = &b;
	printf("%d", p - q);
	return 0;
}
