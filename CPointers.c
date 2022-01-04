
#include <stdio.h>

int main()
{
    const int a;  // The “a” is a constant integer.
    int const b;  // The “a” is a constant integer.
    const int *c;  // Here “a” is a pointer to a const integer, the value of the integer is not modifiable, but the pointer is modifiable.
    int * const d;  // Here “a” is a const pointer to an integer, the value of the pointed integer is modifiable, but the pointer is not modifiable. 
    // It compiles ?
    //int const * e const; // Here “a” is a const pointer to a const integer that means the value of the pointed integer and pointer both are not modifiable.

    return 0;
}
