#pragma once 
#include<forward_list>

class SortedList {

public:
    SortedList();
    void addToList(std::pair<std::string, int> x);
    void printList();

private:
    const int capacity = 10;
    int size = 0;
    std::forward_list<std::pair<std::string, int>> list;       
    std::forward_list<std::pair<std::string, int>>::iterator iterator;      
    void modifyDuplicateEntry(std::pair <std::string, int> x);
};
