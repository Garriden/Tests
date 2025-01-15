#include <iostream>
#include <vector>

/*
  Majority. Return the element that appears at least n/2 times.

  Brute force: For each element, check how many equal elements do we have in the vector.
    Time complexity: O(n^2)
    Space complexity O(1)

  Without auxiliar buffer/data structure:
      - Sort vector.
      - Iterate and count.
    Time complexity: O(n log n)
    Space complexity O(1)

  Map:
      - Iterate vector and build map.
      - Iterate map.
    Time complexity: O(n)
    Space complexity O(n) map should be maximum n/2 space -> n

  How to do it in O(n) time and O(1)?
    Boyer-Moore Voting Algorithm
    Just iterate the vector one time. Polling system.
    If there is one count: that is, an element that occurs repeatedly for more than half of the elements of the input.

    Time complexity: O(n)
    Space complexity: O(1)
*/

int getMajority(const std::vector<int> &v)
{
    int count = 0;
    int posibleMajority = 0;

    for(int ii = 0; ii < v.size(); ++ii) {
        if(count == 0) {
            posibleMajority = v[ii];
            count = 1;
        } else if(v[ii] == posibleMajority) {
            ++count;
        } else {
            --count;
        }
    }

    // If you want to check the existence of the element, you could iterate the vector again.

    return posibleMajority;
}

int main()
{
    std::vector<int> v1{3,2,3};
    std::vector<int> v2{2,2,1,1,1,2,2};

    std::cout << getMajority(v1) << std::endl;
    std::cout << getMajority(v2) << std::endl;
}