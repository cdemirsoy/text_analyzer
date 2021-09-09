#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <queue>
#include <vector>
#include <forward_list>
#include <boost/algorithm/string.hpp>
#include "TextAnalyzer.hpp"
#include "SortedList.hpp"

using namespace std;
using namespace boost;


TextAnalyzer::TextAnalyzer(const Arguments& cmdArguments) : numWords(cmdArguments.numWords), fileName(cmdArguments.filePath), 
    outputFormat(cmdArguments.outputFormat) { 
        //cout << "constructing TextAnalyzer\n";
        myList.setCapacity(numWords);
    }
TextAnalyzer::~TextAnalyzer() {}

void TextAnalyzer::procesText() {

    string line, currentWord;
    fileStream.open(fileName, ifstream::in);

    if (fileStream.is_open()) {
        while(fileStream.good() && getline(fileStream, line)) {
            stringstream ls(line);
                    
            while(ls >> currentWord) {

                if (!processIfSmiley(line, currentWord)) {
                    currentWord = sanitize(currentWord);
                    if (currentWord.length()==0)
                        continue;
                
                    if (wordMap.find(currentWord) == wordMap.end()) {
                        wordMap[currentWord] = 1; 
                    }
                    else {
                        wordMap[currentWord]++;
                    }
                    myList.addToList(std::make_pair(currentWord, wordMap[currentWord]));
                }       
            }
            numOfSmileyInLine = 0;
            lineNumber++;
        }
        fileStream.close();
        myList.reverseList();
    }
    else 
    {
        cerr << "Couldn't open the file." << endl;
        return;
    }
}
    
void TextAnalyzer::printText() const{ 

    if (!outputFormat.compare("cmd")){
        myList.printListConsole(smileyPositions);
    }
    else if (!outputFormat.compare("txt")){
        myList.printListText(smileyPositions);
    }
    else if (!outputFormat.compare("xml")){
        myList.printListXML(smileyPositions);
    }
    else {
        cout << "unsupported outputFormat\n";
    }
}

string TextAnalyzer::sanitize(string& toSanitize) const {
    algorithm::to_lower(toSanitize);
    string sanitized = "";
    for (auto& ch : toSanitize){
        if (ch >= 'a' && ch <= 'z')
            sanitized += ch;
        else
            return sanitized;
    }
    return sanitized;
}

bool TextAnalyzer::processIfSmiley (string& line, const string& currentString) {
    
    if (isSmiley(currentString)) {
        //cout << "line beg: " << line << endl;
        unsigned int currentColumn = line.find(':');
        //cout << "curcol: " << currentColumn << endl;
        unsigned int currentPos = currentColumn+numOfSmileyInLine+1;
        smileyPositions.push_back(std::make_pair(lineNumber, currentPos));
        //cout << "to erase " << currentColumn << endl;
        line.erase(currentColumn, 1);
        //cout << "line end: " << line << endl;

        numOfSmileyInLine++;
        return true;
    }
    else {
        return false;
    }
}

bool TextAnalyzer::isSmiley (const string& currentString) const {
    if (currentString[0] == ':') {
        return true;
    }
    else {
        return false;
    }
}

 pair<unsigned int, unsigned int> TextAnalyzer::getPositionList(unsigned int index) const {
        return smileyPositions[index];
} 

forward_list<std::pair<std::string, unsigned int>> TextAnalyzer::getSortedList() {
    return myList.getList();
}