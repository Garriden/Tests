/*
Explanation
Here a variable a holds the value 130 of integer datatypes, which is then type casted to char datatypes using pointer variable. 
As we know that a value 130 is exceeding the char, 2^8 -> 256, range( -128 to 127), thus it loops through its range.

For Example
128 = -128
129 = -127
130 = -126
*/

#include<stdio.h>
int main(){
	int a = 130;
	char *ptr;
	ptr = (char *)&a;
	printf("%d ",*ptr);
	return 0;
}
