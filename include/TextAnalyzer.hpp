#pragma once 
#include <string>
#include <fstream>
#include <vector>
#include<forward_list>
#include<map>
#include "include/SortedList.hpp"

class TextAnalyzer {

public:
    TextAnalyzer(const std::string& fileName, unsigned int numWords);
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
    std::string fileName;
    std::string currentWord;
    std::map<std::string, int> wordMap;
    SortedList myList;

    std::string sanitize(std::string& toSanitize);
    bool isSmiley (std::string& line, std::string currentString);
};