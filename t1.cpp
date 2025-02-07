#include <vector>
#include <unordered_set>
#include <iostream>

int solve(int w0, int w1, int w2)
{
    if(w0 >= w1 && w0 >= w2) {
        return 0;
    } else if(w1 >= w0 && w1 >= w2) {
        return 1;
    } else {
        return 2;
    }

    return -1;
}


int main() 
{
    std::cout << solve(20, 59, 8) << std::endl;

    return 0;
}