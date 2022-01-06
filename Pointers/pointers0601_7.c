/*
11

Here a pointer variable ptr holds the address of a first value (2) of an object cr, 
then the address of the pointer variable is incremented by 4 and then its value is displayed.

For Example
*(ptr + 0) = 2
*(ptr + 1) = 3
*(ptr + 2) = 5
*(ptr + 3) = 7
*(ptr + 4) = 11
*(ptr + 5) = 13
*/

#include<stdio.h>
struct classroom
{
	int students[7];
};
int main()
{
	struct classroom cr = {2, 3, 5, 7, 11, 13};
	int *ptr;
	ptr = (int *)&cr;
	printf("%d",*(ptr + 4));
	return 0;
}
