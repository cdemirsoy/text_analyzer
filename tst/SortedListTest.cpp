#include <iostream>
#include <fstream>
#include <map>
#include <queue>
#include <vector>
#include <forward_list>
#include <boost/algorithm/string.hpp>
#include "SortedList.hpp"
#include "gtest/gtest.h"

using namespace std;
using namespace boost;

static bool isEqualPair(std::pair<std::string, unsigned int> a, std::pair<std::string, unsigned int> b) {

    if ((a.second == b.second) && (a.first ==  b.first))
        return true;
    else
        return false;
}

class MockList : public SortedList {

public:
    using SortedList::SortedList;
    unsigned int getSize() {
        return size;
    }
    unsigned int getCapacity() {
        return capacity;
    }
    auto getList() {
        return list;
    }

};

TEST(SortedList, addSameWord) {
    MockList sortedList;
    sortedList.setCapacity(10U);
    ASSERT_EQ(sortedList.getCapacity(), 10U);
    sortedList.addToList(std::make_pair("SomeWord", 1));
    ASSERT_EQ(sortedList.getSize(), 1U);
    sortedList.addToList(std::make_pair("SomeWord", 2));
    ASSERT_EQ(sortedList.getSize(), 1U);
    sortedList.addToList(std::make_pair("SomeWord", 3));
    ASSERT_EQ(sortedList.getSize(), 1U);
}

TEST(SortedList, addDifferentWords) {
    MockList sortedList;
    sortedList.setCapacity(10U);
    ASSERT_EQ(sortedList.getCapacity(), 10U);
    sortedList.addToList(std::make_pair("SomeWord1", 1));
    ASSERT_EQ(sortedList.getSize(), 1U);
    sortedList.addToList(std::make_pair("SomeWord2", 1));
    ASSERT_EQ(sortedList.getSize(), 2U);
    sortedList.addToList(std::make_pair("SomeWord3", 1));
    ASSERT_EQ(sortedList.getSize(), 3U);
}

TEST(SortedList, modifyList) {
    MockList sortedList;
    sortedList.setCapacity(3);
    ASSERT_EQ(sortedList.getCapacity(), 3U);
    std::pair<string, int> pair1 ("SomeWord1",1);
    std::pair<string, int> pair2 ("SomeWord2", 100);
    std::pair<string, int> pair3 ("SomeWord3", 50);
    std::pair<string, int> pair4 ("SomeWord4", 2);
    sortedList.addToList(pair1);
    ASSERT_EQ(sortedList.getSize(), 1U);
    sortedList.addToList(pair2);
    ASSERT_EQ(sortedList.getSize(), 2U);
    sortedList.addToList(pair3);
    ASSERT_EQ(sortedList.getSize(), 3U);
    sortedList.addToList(pair4);
    ASSERT_EQ(sortedList.getSize(), 3U);
    sortedList.reverseList();

    std::forward_list list = sortedList.getList();

    ASSERT_EQ(isEqualPair(*(list.begin()), pair1), false);
    ASSERT_EQ(isEqualPair(*(list.begin()), pair2), true);
    list.pop_front();
    ASSERT_EQ(isEqualPair(*(list.begin()), pair3), true);
    list.pop_front();
    ASSERT_EQ(isEqualPair(*(list.begin()), pair4), true);

}
    