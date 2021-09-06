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

SortedList::SortedList(int numOccurences) : capacity(numOccurences){
    cout << "constructing list of "<< numOccurences << endl;
}

void SortedList::addToList(std::pair<string,int> x) {
        
    if (list.empty()){
        list.push_front(x);
        size++;
        return;
    }
        
    modifyDuplicateEntry(x);
        
    return;
}
    
void SortedList::printList() {
    for (auto& pair : list)
        cout << "Pairs: " << pair.first << "\t" << pair.second << endl;
}

 
        
void SortedList::modifyDuplicateEntry(std::pair<string,int> x){

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
