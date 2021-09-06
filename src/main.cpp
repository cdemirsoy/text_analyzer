#include <iostream>
#include <fstream>
#include "main_utility.hpp"
#include <string>
#include "string.h"

using namespace std;

int main(int argc, char* argv[]) {

    string filePath, outputFormat = "cmd";
    unsigned int numWords = 10;

    if (!parse_arguments(argc, argv, filePath, outputFormat, numWords)) {
        cout << "parse error\n";
        return 1;
    }

    cout << "parsed values, filePath: " << filePath << " outputFormat: " << outputFormat << " numWords: " << numWords << endl;

    ifstream myFile(filePath, ifstream::in);

    while (myFile.fail()) {
        cout << "File not found, terminating" << endl;
        return 1;
    }

    myFile.close();
    
    TextAnalyzer textAnalyzer(filePath, numWords);
    executeAnalysis(textAnalyzer);

    return 0;
}

