/*
4, 8?, why 8?
Since ptr is a pointer variable of integer data types.
*/

#include<stdio.h>
int main(){
	int *ptr, b;
	int v;
	b = sizeof(v);
	printf("%d \n" , b);
	
	b = sizeof(ptr);
	printf("%d" , b);
		
	return 0;
}
