#pragma once 
#include<forward_list>

class SortedList {

public:
    SortedList(unsigned int numOccurences);
    void addToList(std::pair<std::string, int> x);
    void printListConsole();
    void printListText();
    void printListXML();


private:
    const unsigned int capacity;
    int size = 0;
    std::forward_list<std::pair<std::string, int>> list;       
    std::forward_list<std::pair<std::string, int>>::iterator iterator;      
    void modifyDuplicateEntry(std::pair<std::string, int> x);
};
