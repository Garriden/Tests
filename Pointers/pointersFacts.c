/*
Features of Pointers:

- Pointers save memory space.

- Execution time with pointers is faster because data are manipulated with the address, 
that is, direct access tomemory location.

- Memory is accessed efficiently with the pointers. 
The pointer assigns and releases the memory as well. 
Hence it can be said the Memory of pointers is dynamically allocated.

- Pointers are used with data structures. 
They are useful for representing two-dimensional and multi-dimensional arrays.

- An array, of any type can be accessed with the help of pointers,
without considering its subscript range.

- Pointers are used for file handling.

- Pointers are used to allocate memory dynamically.

- In C++, a pointer declared to a base class could access the object of a derived class. 
However, a pointer to a derived class cannot access the object of a base class.

*/



#include <stdio.h>

int main()
{
    int    a =  3;
    int   *b = &a;
    int  **c = &b;
    int ***d = &c;
    
    // Dereferencing an (int ***) once gets you an (int **) (3 - 1 = 2)
    *d ==   c; 
    
    // Dereferencing an (int ***) twice, or an (int **) once, gets you an (int *) (3 - 2 = 1; 2 - 1 = 1)
    **d ==  *c ==  b; 
    
    // Dereferencing an (int ***) thrice, or an (int **) twice, or an (int *) once, 
    // gets you an int (3 - 3 = 0; 2 - 2 = 0; 1 - 1 = 0)
    ***d == **c == *b == a == 3; 

    return 0;
}
