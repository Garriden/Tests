/*
Adress, Adress
& and * cancelled each other and display the address stored in a pointer variable ptr
i.e) the address of a.
*/

#include<stdio.h>

int main(){
	int a = 36;
	int *ptr;
	ptr = &a;
	printf("%u %u", *&ptr , &*ptr);
	return 0;
}
