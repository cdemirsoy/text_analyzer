#pragma once 
#include<forward_list>

/**
 * Custom comparator to sort occurence list with given pairs, which is a forward list. If occurences are equal, 
 * alphabetical order is applied.
 * \param[in]  a     LHS for the comparison, which is a pair of word and occurence.
 * 
 * \param[in]  b     RHS for the comparison, which is a pair of word and occurence.
 * 
 * \param[out] ret   Result of the comparison made.
 */
bool cmp_fun(std::pair<std::string, unsigned int> a, std::pair<std::string, unsigned int> b);

/**
 * Class that keeps an ordered list for number of occurences.
 *  
 * * SortedList: Constructor to create utilites to keep and accordingly manipulate the list of occurences.
 * *    \param[in]  numWords  Maximum size or capactiy of the linked list that keeps ordered number of word occurences.
 * *
 * * ::addToList: Function that takes a word and occurence pair, and updates the sorted occurence list accordingly.
 * *   For the first occurence (i.e., when the list is empty), pair is directly pushed into the list, otherwise modifyList is called
 * *   to do certain checks and modify the occurence list if needed.
 * *    \param[in]  occurencePair  Occurence pair to process.
 * *
 * * ::printListConsole: Prints the occurence list to the commandline.
 * *
 * * ::printListText: Creates a txt file and outputs the occurence list into it.
 * *
 * * ::printListXML:  Creates an xml file and outpits the occurences list into it using the hardcoded format.
 * *   position of the smiley is saved into the list. If word is not a smiley and a valid word, it is added to the list.
 * *
 * * ::reverseList: Function that provides interface to reverse the occurence list, used to achieve descending order of occurences.
 * *
 */
class SortedList final {

public:
    SortedList(unsigned int numWords);
    void addToList(std::pair<std::string, unsigned int> occurencePair);
    void printListConsole() const;
    void printListText()    const;
    void printListXML()     const;
    void reverseList();

private:
    const unsigned int capacity;
    unsigned int size = 0;
    std::forward_list<std::pair<std::string, unsigned int>> list;       
    void modifyList(std::pair<std::string, unsigned int> occurencePair);
};
