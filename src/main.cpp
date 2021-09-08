#include "MainUtility.hpp"


using namespace std;

int main(int argc, char* argv[]) {

    Arguments cmdArguments;

    if (0 != parse_arguments(argc, argv, cmdArguments)) {
        return 1;
    }

    cout << endl << "TextAnalyzer configuration:" << endl 
                 << " filePath:\t"     << cmdArguments.filePath << endl 
                 << " outputFormat:\t" << cmdArguments.outputFormat << endl 
                 << " numWords:\t"     << cmdArguments.numWords << endl <<endl;


    if (checkInputFile(cmdArguments.filePath)) {
        cout << "File not found, terminating!\n";
        return 1;
    }
   
    TextAnalyzer textAnalyzer(cmdArguments);

    executeAnalysis(textAnalyzer);

    return 0;
}

