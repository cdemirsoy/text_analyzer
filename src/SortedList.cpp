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

bool cmp_fun(std::pair<string,int> a, std::pair<string,int> b) {
   return a.second < b.second;
}

SortedList::SortedList(unsigned int numWords) : capacity(numWords){
    cout << "constructing list of "<< numWords << endl;
}

void SortedList::addToList(std::pair<string, unsigned int> x) {
        
    if (list.empty()){
        list.push_front(x);
        size++;
        return;
    }
        
    modifyList(x);
        
    return;
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

 
        
void SortedList::modifyList(std::pair<string, unsigned int> x){

    bool isEligible = x.second > list.begin()->second ? true : false;
    for (iterator = list.begin(); iterator != list.end(); ++iterator) {
                
        if (iterator->first == x.first){
            iterator->second = x.second;
            list.sort(cmp_fun);
            return;
        }
    }
            
    if (isEligible || size < capacity) {
        list.push_front(x);
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
