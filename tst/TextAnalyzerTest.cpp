#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <queue>
#include <vector>
#include <forward_list>
#include <boost/algorithm/string.hpp>
#include "TextAnalyzer.hpp"
#include "SortedList.hpp"
#include "gtest/gtest.h"

using namespace std;
using namespace boost;

static bool isEqualPair(std::pair<unsigned int, unsigned int> a, std::pair<unsigned int, unsigned int> b) {

    if ((a.second == b.second) && (a.first ==  b.first))
        return true;
    else
        return false;
}





class MockList : public TextAnalyzer {

public:
    using TextAnalyzer::TextAnalyzer;

    /*
    bool isSmileyTest (const std::string& currentString) const {
        return isSmiley(currentString);
    }

    bool processIfSmileyTest (std::string& line, const std::string& currentString) {
        return processIfSmiley(line, currentString);
    }
    
    pair<unsigned int, unsigned int> getPositionList(unsigned int index) const {
        return smileyPositions[index];
    } 
    */
  

};



TEST(TextAnalyzer, isSmiley) {
    Arguments cmdArguments;
    cmdArguments.filePath = "ss";

    cout << "vals: " << cmdArguments.numWords << " " << cmdArguments.outputFormat << " " << cmdArguments.filePath << endl;
    TextAnalyzer textAnalyzer(cmdArguments);
    
    
    string smiley1 {":)"};
    string smiley2 {":-)"};
    string smiley3 {":-))"};
    string smiley4 {"))"};
    
    ASSERT_EQ(textAnalyzer.isSmiley(smiley1), true);
    ASSERT_EQ(textAnalyzer.isSmiley(smiley2), true);
    ASSERT_EQ(textAnalyzer.isSmiley(smiley3), true);
    ASSERT_EQ(textAnalyzer.isSmiley(smiley4), false);
    
    cout << "finishing\n";
}


TEST(TextAnalyzer, isSmileyAndCheckPositions) {
    Arguments cmdArguments;
    TextAnalyzer textAnalyzer(cmdArguments);
    string testString {"Canberk is the right candidate :)    :):)"}; 
    string smiley {":)"};
    ASSERT_EQ(
        textAnalyzer.processIfSmiley(testString, smiley), 
        true);
    ASSERT_EQ(
        textAnalyzer.processIfSmiley(testString, smiley), 
        true);
    ASSERT_EQ(
        textAnalyzer.processIfSmiley(testString, smiley), 
        true);

    std::pair<unsigned int, unsigned int> result1 (1U, 32U);
    std::pair<unsigned int, unsigned int> result2 (1U, 38U);
    std::pair<unsigned int, unsigned int> result3 (1U, 40U);

    ASSERT_EQ(
        isEqualPair(textAnalyzer.getPositionList(0U), result1), 
        true);

    ASSERT_EQ(
        isEqualPair(textAnalyzer.getPositionList(1U), result2), 
        true);

    ASSERT_EQ(
        isEqualPair(textAnalyzer.getPositionList(2U), result3), 
        true);

}