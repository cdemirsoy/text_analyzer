#include <iostream>
#include <fstream>
#include "TextAnalyzer.hpp"
#include <string>
#include "string.h"
using namespace std;


void executeTests(TextAnalyzer& textAnalyzer) {
    textAnalyzer.procesText();
    textAnalyzer.printText();
    textAnalyzer.printSmileys();
}

static void show_usage(std::string name)
{
    std::cerr << "Usage: " << name << " <option(s)> --filename NameOfTheFile --filepath PathOfTheFile --outputformat OutputFormat\n"
              << "Options:\n"
              << "\t-h, --help\t\t\t\tShow this help message\n"
              << "\t-f, --filename\t\tFILENAME\tSpecify the path of the input file\n"
              << "\t-o, --outputformat\tOUTPUTFORMAT\tSpecify the format of the output file (e.g., xml, txt, cmd)\n"
              << std::endl;
}

static int parse_arguments(int argc, char* argv[], string& filePath, string& outputFormat){

    if (argc < 2){
        cout << "Not enough arguments, run -h or --help\n";
        return 0;
    }
    else if ( strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0 )
    {
        cout << "argv[1]: " << argv[1] << endl;
        show_usage(argv[0]);
        return 0;
    }

    for (int i = 1; i < argc; ++i) {
     
        if (strcmp(argv[i], "-f") == 0 || strcmp(argv[i], "--filepath") == 0 ) {

            if (i + 1 < argc) 
                filePath = argv[++i];
            else {
                std::cerr << "--filepath option requires one argument." << std::endl;
                return 0;
            }  
        } 
        else if (strcmp(argv[i], "-o") == 0 || strcmp(argv[i], "--outputformat") == 0) {

            if (i + 1 < argc) 
                outputFormat = argv[++i];
            else {
                std::cerr << "--outputformat option requires one argument." << std::endl;
                return 0;
            }  
        }
    }
    cout << "nice\n";
    return 1;
}



int main(int argc, char* argv[]) {

    std::string filePath;
    std::string outputFormat;
    cout << "argc: " << argc << endl;

    if (!parse_arguments(argc, argv, filePath, outputFormat)) {
        cout << "parse error\n";
        return 1;
    }

    

    cout << "parsed values, filepath: " << filePath << " outputFormat: " << outputFormat << endl;


    ifstream myFile(filePath, ifstream::in);

    while (myFile.fail()) {
        cout << "File not found, terminating" << endl;
        return 1;
    }

    myFile.close();
    
    TextAnalyzer textAnalyzer(filePath);
    executeTests(textAnalyzer);

    return 0;
}

