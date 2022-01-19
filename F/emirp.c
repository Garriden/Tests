/*
Find the 55th EMIRP number

An emirp ("prime" spelled backwards) is a prime whose (base 10) 
reversal is also prime, but which is not a palindromic prime. 
The first few are 13, 17, 31, 37, 71, 73, 79, 97, 107, 113, 149, 157 ...
*/

#include <stdio.h>

int isPrime(int n) {
    for(int ii=2; ii < n/2; ++ii) {
        if(n%ii == 0) return 0;
    }
    return 1;
}

int reverseNumber(int n) {
    int ret = 0;
    int base = n;
    while(base > 9) {
        ret += base%10;
        ret = ret * 10;
        base /= 10;
    }
    ret += base;
    //printf("       %d \n", ret);
    
    return ret;
}

int main() {
	
	int cont = 0;
	int ii = 12;
	
	while (cont <= 55) {
	    ii++;
    	if(isPrime(ii)) {
    	    int rev = reverseNumber(ii);
    	    if(isPrime(rev) && rev != ii) {
    	        printf("%d \n", ii);
    	        cont++;
    	    }
    	}

	}

    printf("55th emirp: %d \n", ii);

    return 0;
}
