/*
1, 4, 8
Initializing pointer variable to zero is possible. (1 too ? )

Since initial address of any 
data type is zero, So its next address will be size of data type.

Here a pointer variable *p belongs to char data type, thus a = (int) (p + 1); 
increase its address by 1 as it belongs to char datatype. Thus variable a = 1.

Here a pointer variable *q belongs to int data type, thus b = (int) (q + 1); 
increase its address by 4 as it belongs to int datatype. Thus variable b = 4.

Here a pointer variable *r belongs to double data type, thus c = (int) (r + 1); 
increase its address by 8 as it belongs to double datatype. Thus variable c = 8.
*/

#include<stdio.h>

int main(){
	int a, b, c;
	char *p = 0;
	int *q = 0;
	double *r = 0;
	a = (int)(p + 1);
	b = (int)(q + 1);
	c = (int)(r + 1);
	printf("%d %d %d",a, b, c);
	return 0;
}
