#pragma once 
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include "SortedList.hpp"

/**
 * Structure that contains the parsed command line arguments.
 */
struct Arguments {
    std::string filePath;
    std::string outputFormat{"cmd"};
    unsigned int numWords{10};
};

/**
 * Class that encapsulates the intended text analysis.
 *  
 * * ::processText: Utility to open the file and to parse the words to count into the occurence list, as well as the smiley positions.
 * *   File is read line by line, and then the individual words within a line checked whether it is a word or smiley. If a smiley, 
 * *   position of the smiley is saved into the list. If word is not a smiley and a valid word, it is added to the list.
 * 
 * * ::printText: Utility to print the word occurences list, in the intended format.
 */
class TextAnalyzer final {

public:
    TextAnalyzer(const Arguments& cmdArguments);
    void procesText();
    void printSmileys() const;  
    void printText()    const;
    
private:
    unsigned int lineNumber{1U};
    unsigned int numOfSmileyInLine{0U};
    unsigned int numWords;

    const std::string fileName;
    const std::string outputFormat;

    std::map<std::string, unsigned int> wordMap;
    std::vector<std::pair<unsigned int, unsigned int>> smileyPositions;
    SortedList myList;
    std::ifstream fileStream;

    std::string sanitize(std::string& toSanitize) const;
    bool isSmiley (std::string& line, const std::string& currentString);
};