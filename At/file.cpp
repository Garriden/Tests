#include "utils.hpp"
#include "file.hpp"
#include <filesystem>
#include <iostream>
#include <fstream>

std::string File::ReadFile(const std::string &filePath)
{
    // Find file.
    std::filesystem::path path{ filePath };
    std::string ret = "";

    // Read file.
    std::error_code error;
    if(std::filesystem::exists(path, error)) {
        std::ifstream ifs(path);
        std::string line;
        
        while(std::getline(ifs, line)) { // Read line by line
            ret += ParseLine(line);
        }
        ifs.close();
    } else {
        std::cout << "File doesnt exist: " << filePath << " / " << error.message() << std::endl;
        //std::cout << "Creating new file..." << std::endl;
        //std::ofstream ofs(path);
    }

    return ret;
}

std::pair<std::string, std::string> File::ReadTwoListsFromFile(const std::string &filePath)
{
    // Find file.
    std::filesystem::path path{ filePath };
    std::pair<std::string, std::string> ret = {"", ""};

    // Read file.
    std::error_code error;
    if(std::filesystem::exists(path, error)) {
        std::ifstream ifs(path);
        std::string line;

        bool isListA = false;
        bool isListB = false;
        while(std::getline(ifs, line)) { // Read line by line

            // Check if we are building lista a or b.
            if(line == ("LISTA A")) {
                isListA = true;
                isListB = false;
            } else if(line == "LISTA B") {
                isListA = false;
                isListB = true;
            } else {

                if(isListA) { 
                    // List a, already parsed.
                    ret.first += line + '\n';
                } else if(isListB) { 
                    // List b, parse.
                    ret.second += ParseLine(line);
                } else {
                    std::cout << "[ERROR] Cannot find LISTA A and LISTA B in input file." << std::endl;
                    break;
                }
            }
        }
        ifs.close();
    } else {
        std::cout << "[ERROR] File doesnt exist: " << filePath << " / " << error.message() << std::endl;
    }

    return ret;
}


int File::WriteNewFile(const std::string &dataToWrite, const std::string &filePath)
{
    if(E_KO == DeleteLocalFile(filePath)) {
        return E_KO;
    }

    // Find file.
    std::filesystem::path path{ filePath };

    // Write it into file in append mode.
    std::ofstream ofs(path, std::ios_base::app);

    ofs << dataToWrite;
    ofs.close();

    return E_OK;
}

int File::DeleteLocalFile(const std::string &filePath)
{
    std::filesystem::path path{ filePath };

    std::error_code error;
    if(!std::filesystem::remove(path, error)) {
        std::cout << "! Could not remove the file: " << filePath << ". Error: " << error.message() << std::endl;
        return E_KO;
    }

    return E_OK;
}

std::string File::ParseLine(const std::string &s)
{
    std::string alphaNumericString = "";

    for(char c : s) {
        // Get just the alphanumeric characters.
        if(std::isalnum(c) || c == ' ') {
            alphaNumericString += std::tolower(c); // Convert to lowercase if necessary.
        } else {
            // Ex: Treat http://209:153:231:131 as different words (http   209 153 231 131).
            alphaNumericString += ' ';
        }
    }
    
    return alphaNumericString + '\n';
}