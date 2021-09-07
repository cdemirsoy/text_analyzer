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

SortedList::SortedList(unsigned int numWords) : capacity(numWords){
    cout << "constructing list of "<< numWords << endl;
}

void SortedList::addToList(std::pair<string, unsigned int> occurencePair) {
        
    if (list.empty()){
        list.push_front(occurencePair);
        size++;
    }
    else {
        modifyList(occurencePair);
    }
}
    
void SortedList::printListConsole() const{
    for (auto& pair : list)
        cout << "Pairs: " << pair.first << "\t" << pair.second << endl;
}

void SortedList::printListText() const{
    ofstream outputFile;
    outputFile.open("analysis.txt", ofstream::out);

    if (outputFile.is_open()) { 
        for (auto& pair : list)
            outputFile << "Pairs: " << pair.first << "\t" << pair.second << endl;

    }
    outputFile.close();

}

void SortedList::printListXML() const{
    ofstream outputFile;
    outputFile.open("analysis.xml", ofstream::out);
    unsigned int rank = size;
    if (outputFile.is_open()) { 
        outputFile << "<occurences>" << endl; 

        for (auto& pair : list) {
            outputFile << "\t<rank id="<< rank-- <<">" << endl;  
            outputFile << "\t\t<word>" << pair.first << "</word>" << endl;
            outputFile << "\t\t<frequency>" << pair.second << "</frequency>" << endl;  
        }
        outputFile << "</occurences>" << endl;  
    }
    outputFile.close();
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
