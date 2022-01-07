/*
t
As pointer variable *ptr is declare under integer datatype, ptr[1] address points to the 
address of arr[4] because the size of integer datatype is 4 where as the size of char datatype is 1. 
Thus the value in arr[4] i.e) t is displayed.
*/

#include<stdio.h>

int main(){
 char arr[15] = "pointer array";
 int *ptr;
 ptr = arr;
 printf("%c",ptr[1]);
 return 0;
}
