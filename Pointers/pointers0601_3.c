/*
Here the characters in string "helloworld" is placed in address as follows. ptr +4 tells the compiler to start reading from 4th place of a string "Helloworld".

Character	address
h	4214784
e	4214785
l	4214786
l	4214787
o	4214788
w	4214789
o	4214790
r	4214791
l	4214792
d	4214793
*/

#include<stdio.h>

int main()
{
	char *ptr = "helloworld";
	printf(ptr + 4);
	return 0;
}
