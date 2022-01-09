/*
Machine dependant.
* Output is 513 in a little endian machine. 
* To understand this output, let integers be stored using 16 bits. 
* In a little endian machine, when we do x[0] = 1 and x[1] = 2, 
* the number a is changed to 00000001 00000010 which is representation
*  of 513 in a little endian machine.
*/

#include<stdio.h> 

int main() 
{ 
   int a; 
   char *x; 
   x = (char *) &a; 
   a = 512; 
   x[0] = 1; 
   x[1] = 2; 
   printf("%dn",a);   
   return 0; 
}
