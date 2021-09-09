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

static bool isEqualPairOccurence(std::pair<std::string, unsigned int> a, std::pair<std::string, unsigned int> b) {

    if ((a.second == b.second) && (a.first ==  b.first))
        return true;
    else
        return false;
}

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

TEST(TextAnalyzer, stringSanitize) {
    Arguments cmdArguments;
    TextAnalyzer textAnalyzer(cmdArguments);
    string testString1 = "ABcxZ";
    string correctResult1 = "abcxz";
    string testString2 = "AbCd''''''''";
    string correctResult2 = "abcd";
    string testString3 = "'abc'";
    string correctResult3 = "";

    testString1 = textAnalyzer.sanitize(testString1);
    testString2 = textAnalyzer.sanitize(testString2);
    testString3 = textAnalyzer.sanitize(testString3);

    ASSERT_EQ(
        testString1.compare(correctResult1), 
        0);

    ASSERT_EQ(
        testString2.compare(correctResult2), 
        0);

    ASSERT_EQ(
        testString3.compare(correctResult3),  
        0);
}

TEST(TextAnalyzer, processText) {
    Arguments cmdArguments;
    
    ofstream outputFile;
    outputFile.open("unitTest.txt", ofstream::out);
    outputFile << "BMW MErcEDES audI bmW AUDI :) mustaNG :) :)" << endl << endl;
    outputFile.close();

    cmdArguments.filePath = "unitTest.txt";
    TextAnalyzer textAnalyzer(cmdArguments);

    textAnalyzer.procesText();

    forward_list<std::pair<std::string, unsigned int>> myList = textAnalyzer.getSortedList();

    std::pair<std::string, unsigned int> result1 ("bmw", 2);
    std::pair<std::string, unsigned int> result2 ("audi", 2);
    std::pair<std::string, unsigned int> result3 ("mustang", 1);
    std::pair<std::string, unsigned int> result4 ("mercedes", 1);

    auto a = myList.begin();

    ASSERT_EQ(
        isEqualPairOccurence(*a, result1), true
    );

    ASSERT_EQ(
        isEqualPairOccurence(*(++a), result2), true
    );

    ASSERT_EQ(
        isEqualPairOccurence(*(++a), result3), true
    );

    ASSERT_EQ(
        isEqualPairOccurence(*(++a), result4), true
    );

}

TEST(TextAnalyzer, printListCMD) {
    Arguments cmdArguments;
    TextAnalyzer textAnalyzer(cmdArguments);
    textAnalyzer.printText();   
}

TEST(TextAnalyzer, printListXML) {
    Arguments cmdArguments;
    cmdArguments.outputFormat = "xml";
    TextAnalyzer textAnalyzer(cmdArguments);
    textAnalyzer.printText();   
}

TEST(TextAnalyzer, printListTXT) {
    Arguments cmdArguments;
    cmdArguments.outputFormat = "txt";
    TextAnalyzer textAnalyzer(cmdArguments);
    textAnalyzer.printText();   
}
