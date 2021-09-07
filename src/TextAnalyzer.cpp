#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <queue>
#include <vector>
#include <forward_list>
#include <boost/algorithm/string.hpp>
#include "include/TextAnalyzer.hpp"
#include "include/SortedList.hpp"

using namespace std;
using namespace boost;

TextAnalyzer::TextAnalyzer(const Arguments& cmdArguments) : numOccurences(cmdArguments.numWords), fileName(cmdArguments.filePath), 
    outputFormat(cmdArguments.outputFormat), myList(cmdArguments.numWords) {
    std::cout << "Constructing\n";
}

void TextAnalyzer::procesText() {

    string line;
    fileStream.open(fileName, ifstream::in);

    if (fileStream.is_open()) {
        while(fileStream.good() && getline(fileStream, line)) {
            columnNumber = 0;
            stringstream ls(line);
                    
            while(ls >> currentWord) {

                if (!isSmiley(line, currentWord)) {
                    currentWord = sanitize(currentWord);
                    if (currentWord.length()==0)
                        continue;
                
                    if (wordMap.find(currentWord) == wordMap.end()) 
                        wordMap[currentWord] = 1; 
                    else {
                        wordMap[currentWord]++;
                    }
                    myList.addToList(std::make_pair(currentWord, wordMap[currentWord]));
                }       
            }
            numOfSmileyInLine = 0;
            prevColumn = 0;
            lineNumber++;
        }
        fileStream.close();
    }
    else 
    {
        cerr << "Couldn't open the file." << endl;
        return;
    }
}
    
void TextAnalyzer::printText(){ 
    cout << "printtext called\n";
    if (!outputFormat.compare("cmd")){
        cout << "printing to console\n";
        myList.printListConsole();
    }
    else if (!outputFormat.compare("text")){
        cout << "printing to txt\n";
        myList.printListText();
    }
    else if (!outputFormat.compare("xml")){
        cout << "printing to xml\n";
        myList.printListXML();
    }
    else {
        cout << "unsupported outputFormat\n";
    }

}

void TextAnalyzer::printSmileys(){        
    for (auto a : smileyPositions)
        cout << "row: " << a.first << " col: " << a.second << endl;
}

string TextAnalyzer::sanitize(string& toSanitize) {
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

bool TextAnalyzer::isSmiley (string& line, string currentString) {
    
    if (currentString[0] == ':') {
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
    else 
        return false;
}
