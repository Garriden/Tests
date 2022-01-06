/*
Here k is the pointer variable which holds the address of another pointer variable j. 
Where j is also a pointer variable which also holds the address of another variable i. 
Now when the address of a pointer variable k is incremented by 1, 
then k hold some other garbage value which is not the address of any other variable. 
runtime? error occurs? I see garbage values.
I suppouse, if 'j' hits memory, it gives garbage, if not, it gives run time error.

1683757328
*/

#include<stdio.h>
int main(){
	int i = 3;
	int *j;
	j = &i;
	j++;
	printf("%d ",*j);
	return 0;
}
