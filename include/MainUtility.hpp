#pragma  once
#include <iostream>
#include <fstream>
#include <string>
#include "string.h"
#include "include/TextAnalyzer.hpp"

using namespace std;

/**
 * Show usage of the commandline parameters, in case of an improper commandline options given.
 * 
 * \param[in]  name    Name of the program binary.
 * 
 */
void show_usage(std::string name);

/**
 * Parse arguments given by the user via commandline. Returns error in case 
 * filepath is not provided.
 * 
 * \param[in]  argc         Number of commandline arguments passed.
 * \param[in]  argv         Pointer to the commandline arguments of char array.
 * \param[out] cmdArguments Arguments struct that store the parsed arguments in a structured way.
 * 
 */
int parse_arguments(const int& argc, char* argv[], Arguments& cmdArguments);

/**
 * Execute the tests required to process the text and collect the intended data as per the request of user.
 * 
 * \param[in]  textAnalyzer Text processor object configured with user inputs to provide utilities 
 *  for the intended text processing.
 * 
 */
void executeAnalysis(TextAnalyzer& textAnalyzer);

/**
 * Check if the given file path corresponds to a file which is workable.
 * 
 * \param[in]  filePath Absolute path to the text file to process.
 * 
 */
int checkInputFile (const string& filePath);
