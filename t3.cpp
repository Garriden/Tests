#include <vector>
#include <iostream>

std::vector<int> spell(std::vector<int> numbers) {

    int size = numbers.size();

    std::vector<int> vAux;

    for(int ii = 0; ii < size; ++ii) {

        if(numbers[size-1-ii] % 2 == 0) {
            vAux.push_back(numbers[size-1-ii]);
        }
    }

    return vAux;
}

int main() {
    std::vector<int> v;
    spell(v);
    return 0;
}