#pragma once 
#include <string>
#include <fstream>
#include <vector>
#include <forward_list>
#include <map>
#include "include/SortedList.hpp"

struct Arguments {
    std::string filePath;
    std::string outputFormat{"cmd"};
    unsigned int numWords{10};
};

class TextAnalyzer {

public:
    TextAnalyzer(const Arguments& cmdArguments);
    void procesText();  
    void printText();
    void printSmileys();
    
private:
    std::ifstream fileStream;
    unsigned int lineNumber=1;
    unsigned int columnNumber=1;
    unsigned int prevColumn=0;
    unsigned int numOfSmileyInLine = 0;
    unsigned int numOccurences;
    std::vector <std::pair<int, int>> smileyPositions;
    const std::string fileName;
    std::string currentWord;
    const std::string outputFormat;
    std::map<std::string, int> wordMap;
    SortedList myList;

    std::string sanitize(std::string& toSanitize);
    bool isSmiley (std::string& line, std::string currentString);
};