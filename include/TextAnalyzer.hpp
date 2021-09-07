#pragma once 
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include "include/SortedList.hpp"

struct Arguments {
    std::string filePath;
    std::string outputFormat{"cmd"};
    unsigned int numWords{10};
};

class TextAnalyzer final{

public:
    TextAnalyzer(const Arguments& cmdArguments);
    void procesText();
    void printSmileys() const;  
    void printText()    const;
    
    
private:
    unsigned int lineNumber{1U};
    unsigned int columnNumber{1U};
    unsigned int prevColumn{0U};
    unsigned int numOfSmileyInLine{0U};
    unsigned int numWords;

    const std::string fileName;
    const std::string outputFormat;
    std::string currentWord;

    std::map<std::string, unsigned int> wordMap;
    std::vector<std::pair<unsigned int, unsigned int>> smileyPositions;
    SortedList myList;
    std::ifstream fileStream;

    std::string sanitize(std::string& toSanitize) const;
    bool isSmiley (std::string& line, std::string currentString);
};