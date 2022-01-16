
 #include <stdio.h>
    
int main()
{
    int ary[4] = {1, 2, 3, 4};
    printf("%d\n", *ary); // 1
    
    int *p = ary;
    printf("%p, %p\n", p, ary); // prints the same adress memory
    
    char *a = NULL;
    if (a) {
        printf(" a ");
    } else {
        printf(" a is NULL \n");
    }
    
    
    int i = 10;
    void *p4 = &i;
    printf("%p\n", (int*)p4); // well deferenced
    
    float i5 = 10;
    void *p5 = &i5;
    printf("%f\n", *(float*)p5);
    
    int *ptr6, a6 = 10;
    ptr6 = &a6;
    *ptr6 += 1;
    printf("%d,%d \n", *ptr6, a6);
    
    *ptr6++;
    printf("%d \n",  a6);
    
    ++*ptr6;
    printf("%d \n",  a6);
    
    *++ptr6;
    printf("%d \n",  a6);
    
    // int *ptsr = &5; //compile error
    
}
