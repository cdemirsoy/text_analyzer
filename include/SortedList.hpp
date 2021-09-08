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
 * *    
 * *        \param[in]  numWords  Maximum size or capactiy of the linked list that keeps ordered number of word occurences.
 * *
 * *
 * * ::addToList: Function that takes a word and occurence pair, and updates the sorted occurence list accordingly.
 * *   For the first occurence (i.e., when the list is empty), pair is directly pushed into the list, otherwise modifyList is called
 * *   to do certain checks and modify the occurence list if needed.
 * *        
 * *        \param[in]  occurencePair  Occurence pair to process.
 * *
 * *
 * * ::printListConsole: Prints the occurence list to the commandline.
 * *
 * *
 * * ::printListText: Creates a txt file and outputs the occurence list into it.
 * *
 * *
 * * ::printListXML:  Creates an xml file and outpits the occurences list into it using the hardcoded format.
 * *   position of the smiley is saved into the list. If word is not a smiley and a valid word, it is added to the list.
 * *
 * *
 * * ::reverseList: Function that provides interface to reverse the occurence list, used to achieve descending order of occurences.
 * *
 * *
 * * ::modifyList: Function that takes a word and occurence pair, and updates the non-empty sorted occurence list accordingly.
 * *   It first finds if the pair is eligible to take place in the list with respect to the number of occurences. Secondly, it check if the occurence
 * *   for the corresponding word is already in the list. If so, it updates the word's occurence in the list and re-sort the list and exits. If the word 
 * *   is not in the list, then it inserts the occurence if there is a free slot in the list, or the word is eligible to add to the list given 
 * *   its occurence number. If either of these conditions hold, the item is inserted to the list and re-sorted. If the size has exceeded capacity with 
 * *   new addition, the word with smallest occurence is extracted from the list.
 * *        
 * *        \param[in]  occurencePair  Occurence pair to process.
 * *
 * *
 */
class SortedList {

public:
    SortedList(unsigned int numWords);
    void addToList(std::pair<std::string, unsigned int> occurencePair);
    void printListConsole(std::vector<std::pair<unsigned int, unsigned int>> smileyPositions) const;
    void printListText(std::vector<std::pair<unsigned int, unsigned int>> smileyPositions)    const;
    void printListXML(std::vector<std::pair<unsigned int, unsigned int>> smileyPositions)     const;
    void reverseList();


protected:
    std::forward_list<std::pair<std::string, unsigned int>> list;       
    unsigned int size = 0;
    const unsigned int capacity;
    void modifyList(std::pair<std::string, unsigned int> occurencePair);
};
