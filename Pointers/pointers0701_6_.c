/*
60
The above program is simply a arithmetic pointer type.
i.e) a * *ptr
i.e) 10 * 6 = 60
*/

#include <stdio.h>

int main()
{
	int a = 10, b = 6;
	int *ptr;
	ptr = &b;
	printf(" %d ", a  **ptr);
	return 0;
}
