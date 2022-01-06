/*   
0 1 
 -------------- 
1 2 
 -------------- 
2 2 2 
 -------------- 
3 3 
 -------------- 
*/


#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int i;
    int *ptr = (int *) malloc(5 * sizeof(int));
    if(ptr == NULL)
    {
        return -1;
    }
    for (i=0; i<5; i++)
    {
        *(ptr + i) = i;
    }

    printf("%d ", *ptr++);
    printf("%d \n -------------- \n", *ptr);
    
    printf("%d ", (*ptr)++);
    printf("%d \n -------------- \n", *ptr);
    
    printf("%d ", *ptr);
    printf("%d ", *++ptr); // nothing
    printf("%d \n -------------- \n", *ptr);    
    
    printf("%d ", ++*ptr);
    printf("%d \n -------------- \n", *ptr);  
    
    return 0;
}
