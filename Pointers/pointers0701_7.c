/*
12
Here, iptr holds the address of first element in an array arr i.e) address of 10. 
In printf statement we increment the address by (2 * sizeof(int)). 
Thus iptr now points to the address of 12. Asterisks (*) in printf statement 
prints the value inside the address i.e) 12 is outputted.
*/

#include<stdio.h>

int main()
{
    int *iptr;
    int i, arr[2][2] = {10, 11, 12, 13};
    iptr = *arr ;
    printf("%d ", *(iptr+2));
    return 0;
}
