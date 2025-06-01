#pragma once
#include <string>

namespace File {
    std::string ReadFile(const std::string &filePath);
    
    std::pair<std::string, std::string> ReadTwoListsFromFile(const std::string &filePath);
    int WriteNewFile(const std::string &dataToWrite, const std::string &filePath);
    int DeleteLocalFile(const std::string &filePath);

    std::string ParseLine(const std::string &s);
};
