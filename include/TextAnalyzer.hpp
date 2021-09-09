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
 * *
 * * ::printText: Utility to print the word occurences list, in the intended format, whether it is xml, txt or commandline.
 * *
 * * ::processIfSmiley: Takes a word as a string, checks if it is a valid smiley, and its location to the smiley position list if so. 
 * *   It removes ':' as a single character from the line to simplify the calculation of column position for subsequent smiley within
 * *   the same line.
 * *
 * *        \param[in]  line           Current line from the text file to be processed.
 * *        \param[in]  currentString  Current word from the line that is being checked for smiley-ness.
 * *        \param[out] line           Line is cleared from ':'s.
 * * 
 * * ::::isSmiley: Checks if a the given string is a valid smiley. Everything starting with a ':' is a valid smiley as defined.
 * *
 * *        \param[in]  currentString  String to check whether it is a smiley.
 */
class TextAnalyzer {

public:
    TextAnalyzer(const Arguments& cmdArguments);
    ~TextAnalyzer();
    void procesText();
    void printText() const;
    bool processIfSmiley (std::string& line, const std::string& currentString);
    bool isSmiley (const std::string& currentString) const;
    std::pair<unsigned int, unsigned int> getPositionList(unsigned int index) const;
    std::string sanitize (std::string& toSanitize) const;
    std::forward_list<std::pair<std::string, unsigned int>> getSortedList();
    
private:
    unsigned int lineNumber{1U};
    unsigned int numOfSmileyInLine{0U};
    unsigned int numWords;

    const std::string fileName;
    const std::string outputFormat;

    std::map<std::string, unsigned int> wordMap;
    SortedList myList;
    std::ifstream fileStream;
    

protected:
    std::vector<std::pair<unsigned int, unsigned int>> smileyPositions;
};