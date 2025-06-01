#include "utils.hpp"

// Detect every word in list B and map it into an unordered map: key = word, value = line.
std::unordered_map<std::string, int> Utils::mapListB(const std::string &listBString, std::vector<std::string> &vectorLineslistB)
{
    std::unordered_map<std::string, int> listBWordLocation;

    std::string currentWord = "";
    std::string currentLine = "";
    int line = 0;
    // Map every word in list B.
    for (int ii = 0; ii < listBString.size(); ++ii) { // For every char - (word) in list B.
        char c = listBString[ii]; 

        if(c == ' ' || c == '\r' || c == '\n') { // Check whitespace or endline.
            if(currentWord != "") { // Word detected.
                listBWordLocation[currentWord] = line; // if repeated, print all lines ? value: vector<int>
                currentLine += currentWord + " ";
                currentWord = "";
            }

            if(c == '\n') { // if endline, increment line counter.
                vectorLineslistB.push_back(currentLine);
                currentLine = "";
                ++line;
            }

        } else { // Still building the word.
            currentWord += c;
        }
    }

    //for(auto pair : listBWordLocation) { // Print map
    //    std::cout << "Key(string): " << pair.first << "   / Value(line): " << pair.second << std::endl;
    //}

    return listBWordLocation;
}

// Iterate through List A and compare if exists in List B.
std::string Utils::CompareListAWordsInListB(const std::string &listAString, const std::unordered_map<std::string, int> &listBWordLocation, const std::vector<std::string> &vectorLineslistB)
{
    int line = 0;
    std::string currentWord = "";
    std::string output = "";
    for (int ii = 0; ii < listAString.size(); ++ii) { //Iterate through list A.
        char c = listAString[ii];
        
        if(c == '\r' || c == '\n') { // Check whitespace or endline.

            if(currentWord != "") { 
                // Check if double word
                int whitespacePosition = currentWord.find(' ');
                if(whitespacePosition != std::string::npos || whitespacePosition == 0 || whitespacePosition == currentWord.size() - 1) {
                    // Double word detected.

                    // Maybe ineficient, I need vectorLineslistB to check these double words.
                    // Check the first word is in the List B map. If exists, check that the second word is also the next one on the list B.
                    std::string word1 = currentWord.substr(0, whitespacePosition);
                    std::string word2 = currentWord.substr(whitespacePosition + 1, currentWord.size() - 1);

                    if(listBWordLocation.count(word1) > 0) { // If word 1 exists in ListBMap
                        int lineLocation = listBWordLocation.at(word1);

                        // Some corner case: Sometimes the second word is NOT the full word. Avoid this case
                        // Current word:  scratch tick 
                        // Current line: [scratch tick]et chuck a luck blackjack roulette cyber
                        int wordPosition     = vectorLineslistB[lineLocation].find(currentWord + ' '); 
                        int wordPositionEndl = vectorLineslistB[lineLocation].find(currentWord + '\n');
                        if(wordPosition != std::string::npos || wordPositionEndl != std::string::npos) {
                            // Current double word exists.
                            output += "A" + std::to_string(line) + " B" + std::to_string(lineLocation) + '\n';
                        }

                    }
                    
                } else {
                    // Normal (single) word detected.
                    if(listBWordLocation.count(currentWord) > 0) {
                        //std::cout << "Word: " << currentWord << " appeared in list B at line: " << listBWordLocation.at(currentWord) << std::endl;
                        output += "A" + std::to_string(line) + " B" + std::to_string(listBWordLocation.at(currentWord)) + '\n';
                    }
                }

                currentWord = "";
            }

            if(c == '\n') { // if endline, increment line counter.
                ++line;
            }
        } else {
            currentWord += c;
        }
    }

    return output;
}