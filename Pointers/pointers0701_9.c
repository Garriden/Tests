/*
ointer-to-String

Here, the starting address i.e) The address of P is skipped
by pre incrementing the address. "Noting more than that".
*/

#include <stdio.h>

int main()
{
	char *ptr = "Pointer-to-String", i;
	printf("%s", ++ptr);
	return 0;
}
