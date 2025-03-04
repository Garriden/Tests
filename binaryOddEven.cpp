#include <iostream>
#include <algorithm>

/*
Binary number on a string
  - If even: Divide by 2.
  - If odd: substract 1.
*/

/* So every 1 bit except for the first one adds 2 steps, 
 and every significant 0 bit adds 1 step. 
*/
int solve3(std::string &S)
{
    int countOnes = 0;
    int countZeros = 0;

    for (int ii = S.find('1'); ii < S.size(); ++ii) {
        //std::cout << S[ii] << std::endl;
        if(S[ii] == '1') {
            countOnes += 2;
        } else {
            ++countZeros;
        }
    }

    return countOnes + countZeros - 1;
}

int solve2(std::string &S)
{
    int countOnes = 0;
    int size = S.size() - S.find('1');

    for(int ii = 0; ii < S.size(); ++ii) {
        if(S[ii] == '1') {
            ++countOnes;
        }
    }

    return countOnes + size - 1;
}

int solve(std::string &S)
{
    int cont = 0;

    while(S.find('1') != std::string::npos) {
        std::cout << S << "  ";
        if(S[S.size() - 1] == '0') { // even.
            std::cout << "EVEN" << std::endl;
            S = S.substr(0, S.size() - 1); // division / 2
        } else { // odd.
            std::cout << "ODD" << std::endl;
            S[S.size() - 1] = '0'; // substract 1
        }
        ++cont;
    }

    return cont;
}

int main()
{
    std::string s1 = "011100";
    std::string s2 = "111";

    std::cout << solve3(s1) << std::endl;
    std::cout << solve3(s2) << std::endl;
}