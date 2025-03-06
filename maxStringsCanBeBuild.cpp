#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>

/*
g++ -o b .\maxStringsCanBeBuild.cpp


 K into combinations
 1st try: more brute force approach.
  - I asume that all characters are appearing in order from a.
  - Choose "ab" and check how many strings has just these characters.
  - Same with "ac".
  - Same with "bc".

  . Should I do a first iteration to check all the characters presents and build the combinations ?


2nd try: What I wanted to try on the online test.
    - Get the most frequent repeated letter which appears on all the strings.
        multimap + decreasing order.
    - DO the brute force approach on step 1.
*/

std::vector<std::string> _combinations;
std::vector<std::pair<char,int> > _charFrequencyVector;

constexpr bool ChooseBigger(const std::pair<int,int>& a, const std::pair<int,int>& b) {
    return a.second != b.second ? a.second > b.second : a.first < b.first;
}

void GetOrderedCharFrequency(std::vector<std::string> &S) {

    std::unordered_map<char, int> charAppearsOnStrings;
    std::unordered_map<char, int> charAppearsOnStringAux;

    // Count character frequencies
    for(std::string s : S) {
        for(char c : s) {

            if(charAppearsOnStringAux[c] == 0) {
                charAppearsOnStrings[c]++;
                charAppearsOnStringAux[c]++;
            }
            
        }
        charAppearsOnStringAux.clear();
    }

    for(auto keyValue : charAppearsOnStrings) {
        //std::cout << keyValue.first << " / " << keyValue.second << std::endl;
        _charFrequencyVector.push_back({keyValue.first, keyValue.second});
    }

    std::sort(_charFrequencyVector.begin(), _charFrequencyVector.end(), ChooseBigger);

    //for(auto elem : _charFrequencyVector) {
    //    std::cout << elem.first << " / " << elem.second << std::endl;
    //}
}

void Combinations(int k, int n, std::vector<bool>& visited, int it) {
    if(k == 0) {
        std::string combi;
        for(int ii = 0; ii < n; ++ii) {
            if(visited[ii]) {
                combi += static_cast<char>(ii + 'a');
            }
        }
        _combinations.push_back(combi);
        //std::cout << combi << std::endl;
    } else {
        for(int ii = it; ii < n; ++ii) {
            if(!visited[ii]) {
                visited[ii] = true;
                Combinations(k - 1, n, visited, ii + 1);
                visited[ii] = false;
            }
        }
    }
}

int Solve(std::vector<std::string> &S)
{
    int maxCount = 0;
    for(std::string combination : _combinations) {
        //std::cout << "combination: " << combination << std::endl;
        int validStringsCount = 0;
        for(auto s : S) {
            //std::cout << "  s: " << s << std::endl;
            int validLettersCount = 0;
            for(char StringLetter : s) {
                //std::cout << "    StringLetter: " << StringLetter << std::endl;
                if(combination.find(StringLetter) != std::string::npos) { //exists
                    ++validLettersCount;
                    //std::cout << "VALID letter!" << std::endl;
                } 
            }

            if(validLettersCount == s.size()) {
                ++validStringsCount;
                //std::cout << "      validStringsCount incremented! " << validStringsCount << std::endl;
            }
        }

        //std::cout << "count = " << maxCount << std::endl;
        if(validStringsCount > maxCount) {
            maxCount = validStringsCount;
        }
    }
    return maxCount;
}

int main()
{
    int k = 2;
    int n = 3; // different letters.
    std::vector<bool> visited(n, false);
    std::vector<std::string> v1 = {"abc", "abb", "cb", "a", "bbb"};

    GetOrderedCharFrequency(v1);

    // O(k*n)
    Combinations(k, n, visited, 0);

    // O(k*n*S.size())
    std::cout << Solve(v1) << std::endl; // 3



    k = 3;
    n = 10; // different letters.
    std::vector<bool> visited2(n, false);
    std::vector<std::string> v2 = {"adf", "jjbh", "jcgj", "ejjj", "adf"};

    Combinations(k, n, visited2, 0);
    std::cout << Solve(v2) << std::endl; // 2



    k = 3;
    n = 8; // different letters.
    std::vector<bool> visited3(n, false);
    std::vector<std::string> v3 = {"abcd", "efgh"};

    Combinations(k, n, visited3, 0);
    std::cout << Solve(v3) << std::endl; // 0


    k = 4;
    n = 7; // different letters.
    std::vector<bool> visited4(n, false);
    std::vector<std::string> v4 = {"bc", "edf", "fde", "dge", "abcd"};

    Combinations(k, n, visited4, 0);
    std::cout << Solve(v4) << std::endl; // 3
}