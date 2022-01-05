//27
#include<stdio.h>

void fun(int *p)
{
  int q = 40;
  p = &q;
}

int main()
{
  int data = 27;
  int *ptr = &data;
  fun(ptr);
  printf("%d", *ptr); // 27
  return 0;
}
