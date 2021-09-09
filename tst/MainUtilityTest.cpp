#include "gtest/gtest.h"
#include "MainUtility.hpp"


TEST(ParseArguments, fewArguments) {
    Arguments cmdArguments;
    char *args[] = {};
    ASSERT_EQ(parse_arguments(1, args, cmdArguments), -1);
}

TEST(ParseArguments, callHelp) {
    Arguments cmdArguments;
    char *args[] = {"binary_name", "-h"};
    ASSERT_EQ(parse_arguments(2, args, cmdArguments), -1);
    args[1] = {"--help"};
    ASSERT_EQ(parse_arguments(2, args, cmdArguments), -1);
}

TEST(ParseArguments, firstArgNotFilePathNorHelp) {
    Arguments cmdArguments;
    char *args[] = {"binary_name", "-o", "SOME_FILE"};
    ASSERT_EQ(parse_arguments(3, args, cmdArguments), -1);
    args[1] = {"--outputFormat"};
    ASSERT_EQ(parse_arguments(3, args, cmdArguments), -1);
}

TEST(ParseArguments, outputFormatNotGiven) {
    Arguments cmdArguments;
    char *args[] = {"binary_name", "-f", "SOME_FILE", "-o"};
    ASSERT_EQ(parse_arguments(4, args, cmdArguments), -1);
    args[3] = {"--outputformat"};
    ASSERT_EQ(parse_arguments(4, args, cmdArguments), -1);
}


TEST(ParseArguments, outputFormatNotSupported) {
    Arguments cmdArguments;
    char *args[] = {"binary_name", "-f", "SOME_FILE", "-o", "UNSUPPORTED_FORMAT"};
    ASSERT_EQ(parse_arguments(5, args, cmdArguments), 0);
    args[3] = {"--outputFormat"};
    ASSERT_EQ(parse_arguments(4, args, cmdArguments), 0);
}

TEST(ParseArguments, numWordsNotGiven) {
    Arguments cmdArguments;
    char *args[] = {"binary_name", "-f", "SOME_FILE", "-n"};
    ASSERT_EQ(parse_arguments(4, args, cmdArguments), -1);
    args[3] = {"--numwords"};
    ASSERT_EQ(parse_arguments(4, args, cmdArguments), -1);
}

TEST(ParseArguments, numWordsRangeCheck) {
    Arguments cmdArguments;
    char *args[] = {"binary_name", "-f", "SOME_FILE", "-n", "100"};
    ASSERT_EQ(parse_arguments(5, args, cmdArguments), -1);
    args[4] = {"0"};
    ASSERT_EQ(parse_arguments(5, args, cmdArguments), -1);
    args[4] = {"20"};
    ASSERT_EQ(parse_arguments(5, args, cmdArguments), 0);
}

TEST(CheckInputFile, checkFile) {
    const string filePath = "UNKNOWN_FILE";
    ASSERT_EQ(checkInputFile(filePath), 1);

}