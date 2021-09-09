#include <iostream>
#include <fstream>
#include "MainUtility.hpp"

#include <string>
#include "string.h"

using namespace std;

void show_usage(std::string name)
{
    std::cerr << "\nUsage: " << name << " <option(s)> --filepath PathToTheFile --outputformat OutputFormat --numwords NumWords\n"
              << "\nOptions:\n"
              << "\t-h, --helpt\t\tHELP\t\tShow this help message\n\n\n"
              << "\t-f, --filepath\t\tFILEPATH\tSpecify the path of the input file\n"
              << "\t-o, --outputformat\tOUTPUTFORMAT\tSpecify the format of the output file e.g., xml, txt, cmd (cmd by default)\n"
              << "\t-n, --numwords\t\tNUMWORDS\tSpecify the number of most frequent words to list (10 by default)\n"
              << std::endl;
}

int parse_arguments(const int& argc, char* argv[], Arguments& cmdArguments){

    if (argc < 2){
        cout << "Not enough arguments, run with -h or --help to see the usage." << endl;
        return -1; 
    }
    else if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0)
    {
        show_usage(argv[0]);
        return -1;
    }

    if (strcmp(argv[1], "-f") == 0 || strcmp(argv[1], "--filepath") == 0) {
        if (argc>2)
            cmdArguments.filePath = argv[2];
    } 
    else {
        cerr << "First argument MUST be the filepath, please revise your input." << endl;
        return -1;
    }

    for (int i = 2; i < argc; ++i) {

        if (strcmp(argv[i], "-o") == 0 || strcmp(argv[i], "--outputformat") == 0) {

            string cmdInput{};
            if (i + 1 < argc) {
                ++i;

                if (strcmp(argv[i], "xml") != 0 && strcmp(argv[i], "txt") != 0 && 
                    strcmp(argv[i], "cmd") != 0) {
                        cout << "Unsupported output format: " << argv[i] << ", using the default format as cmd." << endl;
                }
                else {
                    cmdArguments.outputFormat = argv[i];
                }
            }
            else {
                cerr << "--outputformat option requires one argument." << endl;
                return -1;
            }  
        }
        else if (strcmp(argv[i], "-n") == 0 || strcmp(argv[i], "--numwords") == 0) {

            int cmdInput;
            if (i + 1 < argc) {
                ++i;
                cmdInput = atoi(argv[i]);
                if (cmdInput <= 0 || cmdInput > 40) {
                        cout << "Number of words to list must be between 0 and 40" << endl;
                        return -1;
                }
                else {
                    cmdArguments.numWords = cmdInput;
                }
            }
            else {
                cerr << "--numwords option requires one argument." << endl;
                return -1;
            }  
        }
    }

    return 0;
}

void executeAnalysis(TextAnalyzer& textAnalyzer) {
    textAnalyzer.procesText();
    textAnalyzer.printText();
}

int checkInputFile (const string& filePath) {
    ifstream myFile(filePath, ifstream::in);

    while (myFile.fail()) {
        return 1;
    }

    myFile.close();
    return 0;
}
