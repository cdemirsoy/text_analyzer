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

class MockList : public TextAnalyzer {

public:
    using TextAnalyzer::TextAnalyzer;

    bool isSmileyGet (std::string&& line,  std::string&& currentString){
        return isSmiley(line, currentString);
    }
  

};

TEST(TextAnalyzer, isSmiley) {
    Arguments cmdArguments;
    MockList textAnalyzer(cmdArguments);
    ASSERT_EQ(textAnalyzer.isSmileyGet("", ":)"), true);
    ASSERT_EQ(textAnalyzer.isSmileyGet("",":-)"), true);
    ASSERT_EQ(textAnalyzer.isSmileyGet("",":-))"), true);
    ASSERT_EQ(textAnalyzer.isSmileyGet("","))"), false);
}