#include "main_utility.hpp"


using namespace std;

int main(int argc, char* argv[]) {

    string filePath, outputFormat = "cmd";
    unsigned int numWords = 10;

    if (!parse_arguments(argc, argv, filePath, outputFormat, numWords)) {
        cout << "Argument parsing did not work, terminating\n";
        return 1;
    }

    cout << "parsed values, filePath: " << filePath 
         << " outputFormat: " << outputFormat 
         << " numWords: " << numWords << endl;


    if (!checkInputFile(filePath)) {
        cout << "File not found, terminating\n";
        return 1;
    }
   
    TextAnalyzer textAnalyzer(filePath, numWords, outputFormat);

    executeAnalysis(textAnalyzer);

    return 0;
}

