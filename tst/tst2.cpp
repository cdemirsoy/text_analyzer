#include "gtest/gtest.h"
#include "MainUtility.hpp"

TEST(cmd, test2) {
    //arrange
    //act
    //assert
    //EXPECT_EQ (Formula::bla (0),  0);
   // EXPECT_EQ (Formula::bla (10), 20);
   // EXPECT_EQ (Formula::bla (50), 93);

    Arguments cmdArguments;

    ASSERT_EQ(parse_arguments(1, nullptr, cmdArguments), -1);
    

}