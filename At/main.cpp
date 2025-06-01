#include "utils.hpp"
#include "file.hpp"
#include <iostream>

// g++ -std=c++20 -o exam main.cpp utils.cpp file.cpp
// ./exam
int main(int argc, char *argv[])
{
    // Parse all two files 
    std::pair<std::string, std::string> listsFromInputFile = File::ReadTwoListsFromFile("INPUT.txt");

    std::vector<std::string> vectorLineslistB; // I need it for double words. vector of strings, separated in lines.

    // My idea is to map every word in list B into a map of key = word, value = line number.
    //  Then iterate list A and check if appears in list B and where.

    // Unordered (Hash)map is more eficient than a map. 
    // add: O(1), access: O(n), check exists: O(1).
    std::unordered_map<std::string, int> listBWordLocation = Utils::mapListB(listsFromInputFile.second, vectorLineslistB);

    std::string output = Utils::CompareListAWordsInListB(listsFromInputFile.first, listBWordLocation, vectorLineslistB);

    // Write output into a file.
    if(E_KO == File::WriteNewFile(output, "RESULTS.txt")) {
        std::cout << "[ERROR] Cannot Writte the results file." << std::endl;
    }

    return 0;
}

