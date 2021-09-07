#pragma once 
#include<forward_list>

/**
 * Class that keeps an ordered list for number of occurences.
 *  
 * * SortedList: Constructor to create utilites to keep and accordingly manipulate the list of occurences.
 * *    \param[in]  numWords  Maximum size or capactiy of the linked list that keeps ordered number of word occurences.
 * *
 * * ::addToList: Function that takes a word and occurence pair, and updates the sorted occurence list accordingly.
 * *  For the first occurence (i.e., when the list is empty), pair is directly pushed into the list, otherwise modifyList is called
 * *   position of the smiley is saved into the list. If word is not a smiley and a valid word, it is added to the list.
 * 
 */
class SortedList {

public:
    SortedList(unsigned int numWords);
    void addToList(std::pair<std::string, unsigned int> x);
    void printListConsole() const;
    void printListText()    const;
    void printListXML()     const;
    void reverseList();


private:
    const unsigned int capacity;
    int size = 0;
    std::forward_list<std::pair<std::string, int>> list;       
    std::forward_list<std::pair<std::string, int>>::iterator iterator;      
    void modifyList(std::pair<std::string, int> x);
};
