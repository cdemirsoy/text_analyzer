#pragma once 
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <queue>
#include <vector>
//#include <string>
#include "SortedList.hpp"
#include <forward_list>


#include <boost/algorithm/string.hpp>
using namespace std;
using namespace boost;



class TextAnalyzer{

public:

    TextAnalyzer(const string& fileName) noexcept(false) : fileName(fileName) {
       //fileStream.open(fileName, ifstream::in);
        std::cout << "Constructing\n";
    
    }


    void procesText() {
        fileStream.open(fileName, ifstream::in);

        if (fileStream.is_open()) {
            string line;

            while (fileStream.good()) {
               string line;
                while(getline(fileStream, line)) {
                    columnNumber = 0;
                    //cout << "line: " << line << endl;
                    stringstream ls ( line );
                    string word;   
                    
                    while(ls >> currentWord) {
                
                        //fileStream >> currentWord;
                         //cout << "word: " << currentWord << endl;
                        if (isSmiley(line, currentWord)) {
                            //cout << "smiley found\n";
                        }

                        else {
                            currentWord = sanitize(currentWord);
                            if (currentWord.length()==0)
                                continue;
                            //cout << "word: " << currentWord << endl;
                
                            if (wordMap.find(currentWord) == wordMap.end()) 
                                wordMap[currentWord] = 1; 
                            else {
                                wordMap[currentWord]++;
                      
                            }
                            //cout << "current instance: " << currentWord << ", " << wordMap[currentWord] << endl;
                            myList.addToList(
                                std::make_pair(currentWord, wordMap[currentWord])   
                                );
                        }
                       
                    }
                    numOfSmileyInLine = 0;
                    prevColumn = 0;
                    lineNumber++;
                }
            }

   

        }
        else  // We couldn't open the file. Report the error in the error stream.
        {
            cerr << "Couldn't open the file." << endl;
            //return -1;
        }
    }
    
    void printText(){
        
        myList.printList();
    }
    void printSmileys(){
        
        for (auto a : smileyPositions)
            cout << "row: " << a.first << " col: " << a.second << endl;
    }
    

private:
    ifstream fileStream;
    unsigned int lineNumber=1;
    unsigned int columnNumber=1;
    unsigned int prevColumn=0;
    unsigned int numOfSmileyInLine = 0;
    vector <std::pair<int, int>> smileyPositions;
    string fileName;
    string currentWord;
    std::map<string, int> wordMap;
    SortedList myList;
    //std::set<std::pair<std::string, int>, comp> set;
    //std::priority_queue< myPair, std::vector<myPair>, myComp> sortQueue; 

    string sanitize(string& toSanitize){
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

    bool isSmiley (string& line, string currentString) {
        if (currentString[0] == ':') {
            cout << "line beg: " << line << endl;
            unsigned int currentColumn = line.find(':');
            cout << "curcol: " << currentColumn << endl;
            unsigned int currentPos = currentColumn+numOfSmileyInLine+1;
            smileyPositions.push_back(std::make_pair(lineNumber, currentPos));
            //cout << "to erase " << currentColumn << endl;
            line.erase(currentColumn, 1);
            cout << "line end: " << line << endl;

            numOfSmileyInLine++;
            return true;
        }
        else 
            return false;

    }



};