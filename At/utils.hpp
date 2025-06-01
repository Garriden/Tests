#pragma once
#include <vector>
#include <string>
#include <unordered_map>

// Error messages.
#define E_KO        (-1)
#define E_OK         (0)

namespace Utils {
    std::unordered_map<std::string, int> mapListB(const std::string &listBString, std::vector<std::string> &vectorLineslistB);
    std::string CompareListAWordsInListB(const std::string &listAString, const std::unordered_map<std::string, int> &listBWordLocation, const std::vector<std::string> &vectorLineslistB);
};
