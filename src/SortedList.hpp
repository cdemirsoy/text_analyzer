#pragma once 
#include <iostream>
#include <fstream>
#include <map>
#include <queue>
#include <vector>
//#include <string>
#include "SortedList.hpp"
#include<forward_list>


#include<boost/algorithm/string.hpp>
using namespace std;
using namespace boost;

bool cmp_fun(std::pair<string,int> a, std::pair<string,int> b) {
   return a.second < b.second;
}

class SortedList{
public:

    SortedList(){
        //list.resize(size+1);
    }
    void addToList(std::pair <string, int> x){
        
        //cout << "tuple1: " << x.first << ", " << x.second << endl;
        if ( list.empty() ){
            //cout<< "Initializing empty list\n";
                list.push_front(x);
                size++;
                return;
        }
        
        modifyDuplicateEntry(x);
        
        return;
        

        

        

    }
    
    void printList(){
   
        for (auto& pair : list){
        
            cout << "Pairs: " << pair.first << "\t" << pair.second << endl;
        }


        
    }
    
    private:
        const int capacity = 10;
        int size = 0;
        std::forward_list<std::pair<string, int>> list;
    
        
        std::forward_list<std::pair<string, int>>::iterator iterator;
        
        void modifyDuplicateEntry(std::pair <string, int> x){
            bool isEligible = x.second > list.begin()->second ? true : false;
            for (iterator = list.begin(); iterator != list.end(); ++iterator) {
                
                if (iterator->first == x.first){
                    //cout << "found same key\n";
                    iterator->second = x.second;
                    list.sort(cmp_fun);
                    return;
                }
                
            }
            
            if (isEligible || size < capacity){
                    list.push_front(x);
                    list.sort(cmp_fun);
                    if (++size > capacity){
                        list.pop_front();
                        size--;
                    }
                    
                }
        }
};



