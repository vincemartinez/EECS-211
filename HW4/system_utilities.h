// Prototypes for system-level functitons.

#ifndef UTILITY_HEADERS
#define UTILITY_HEADERS

#include <string>
using namespace std;

// Miscellaneous utilities.
void wait();
void printError(int errcode);

//parsing
int parseCommandLine(string cline, string tklist[]);
void print_token_list(int num, string commands[]);

#endif