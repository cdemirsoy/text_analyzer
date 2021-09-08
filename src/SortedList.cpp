#include <iostream>
#include <fstream>
#include <map>
#include <queue>
#include <vector>
#include <forward_list>
#include <boost/algorithm/string.hpp>
#include "include/SortedList.hpp"

using namespace std;
using namespace boost;

bool cmp_fun(std::pair<std::string, unsigned int> a, std::pair<std::string, unsigned int> b) {

    if (a.second !=  b.second)
        return a.second < b.second;
    else
        return a.first < b.first;
}

SortedList::SortedList(unsigned int numWords) : capacity(numWords) {}

void SortedList::addToList(std::pair<string, unsigned int> occurencePair) {
        
    if (list.empty()){
        list.push_front(occurencePair);
        size++;
    }
    else {
        modifyList(occurencePair);
    }
}
    
void SortedList::printListConsole(std::vector<std::pair<unsigned int, unsigned int>> smileyPositions) const{
    
    cout << "Occurence list:" << endl << endl;
    for (const auto& pair : list)
        cout << "\t" << pair.first << "\t\t" << pair.second << endl;

    cout << endl;

    cout << "Smiley positions: (row, col)" << endl << endl;
    for (const auto& pair : smileyPositions)
        cout << "\t(" << pair.first << ", " << pair.second << ")" << endl;

    cout << endl;
}

void SortedList::printListText(std::vector<std::pair<unsigned int, unsigned int>> smileyPositions) const{
    ofstream outputFile;
    outputFile.open("analysis.txt", ofstream::out);

    if (outputFile.is_open()) { 

        outputFile << "Occurence list:" << endl << endl;

        for (const auto& pair : list)
            outputFile << "\t" << pair.first << "\t\t" << pair.second << endl;

        outputFile << endl;

        outputFile << "Smiley positions: (row, col)" << endl << endl;
        for (const auto& pair : smileyPositions)
            outputFile << "\t(" << pair.first << ", " << pair.second << ")" << endl;

        outputFile << endl;

        outputFile.close();
    }
    else {
        cout << "Could create a text file" << endl;
    }
}

void SortedList::printListXML(std::vector<std::pair<unsigned int, unsigned int>> smileyPositions) const{
    ofstream outputFile;
    outputFile.open("analysis.xml", ofstream::out);
    unsigned int rank = size;

    if (outputFile.is_open()) { 
        
        outputFile << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl; 
        outputFile << "<occurences>" << endl; 

        for (const auto& pair : list) {
            outputFile << "\t<rank id="<< rank-- <<">" << endl;  
            outputFile << "\t\t<word>" << pair.first << "</word>" << endl;
            outputFile << "\t\t<frequency>" << pair.second << "</frequency>" << endl;  
        }

        outputFile << "</occurences>" << endl;  
        outputFile.close();
    }
}

void SortedList::modifyList(std::pair<string, unsigned int> occurencePair){

    bool isEligible = occurencePair.second > list.begin()->second ? true : false;
    std::forward_list<std::pair<std::string, unsigned int>>::iterator iterator;      

    for (iterator = list.begin(); iterator != list.end(); ++iterator) {
                
        if (iterator->first == occurencePair.first){
            iterator->second = occurencePair.second;
            list.sort(cmp_fun);
            return;
        }
    }
            
    if (isEligible || size < capacity) {
        list.push_front(occurencePair);
        list.sort(cmp_fun);
        if (++size > capacity) {
            list.pop_front();
            size--;
        }         
    }
}

void SortedList::reverseList(){
    list.reverse();
}
