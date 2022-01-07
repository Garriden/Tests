/*
Hisis

The above program is some what cool. At first time strlen(str) 
will set to 3 as the character in str is 3. Thus it prints His

After printing His the value in str = is, then at second iteration of for 
loop the strlen(str) will set to 2 Thus is displays is

After printing is the value in str = s, then at third iteration of for loop the strlen(str)
will set to 1 where for(;2<1;) is condition false and it terminate the program after
second iteration of for loop. Thus summation of output is Hisis.
*/

#include <stdio.h>

int main()
{
	char *str = "His";
	for(int i = 0; i < strlen(str); i++) {
	    printf("%s", str++);
	}
	return 0;
}
