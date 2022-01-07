/*
D
The above program is some what tricky. Actually cities[] is an array which has its own address 
and it hold the address of first element( D ) in it as a value. Then integer pointer to pointer variable **i 
is assigned with the address of cities[0]. Now coming to the printf statement, *i tells the printf 
to print the value inside cities[0] which is nothing more than the address of first element in an array,
then **i tells the printf statement to print the value of address stored in cities[0] i.e) D is outputted.
*/

#include <stdio.h>

int main()
{
    char *cities[] = {"Delhi", "London", "Sydney"};
    int **i = &cities[0];
    printf("%c\n", **i);
    return 0;
}
