// This file contains functions used at the system and main level.

#include <iostream>
#include <string>
#include <sstream>
#include "definitions.h"

using namespace std;

void wait() {
	// Prompt user for input and wait.
    string answer;

	cout << "Press ENTER to continue:";
    getline(cin, answer);
	return;
}

void printError(int errcode) {
	
	cout << "  ***ERROR:  ";
	switch(errcode) {
		case BAD_IP_ADDRESS:	
			cout << "Bad IP address.\n";
			break;
		default:
			cout << "Unrecognized error code.\n";
	}
}

int parseCommandLine(string cline, string tklist[]) {

	int token_count = 0;
	int i_first = 0;
	int i_last = 0;
	int j = 0;
	int len = cline.length();
	
	for (int i = 0; i < len; i++){

		if (cline[i] == '"'){

			ostringstream strm;
			i_first = i+1;

			while (cline[i + 1] != '"'){
				i++;
			}

			i_last = i;

			for (j = i_first; j <= i_last; j++){
				strm << cline[j];
			}

			tklist[token_count] = strm.str();
			i = i + 2;
			i_first = i;
			token_count++;

		}

		else if (cline[i] == ' ' && i != 0 && i + 1 < len){

			if (cline[i - 1] != ' '){

				ostringstream strm;
				i_last = i - 1;

				for (j = i_first; j <= i_last; j++){
					strm << cline[j];
				}

				tklist[token_count] = strm.str();
				i_first = i + 1;
				token_count++;

			}
		}

			else if (i == len - 1){

				ostringstream strm;
				i_last = i;

				for (j = i_first; j <= i_last; j++){
					strm << cline[j];
				}

				tklist[token_count] = strm.str();
				token_count++;

			}

	}

    return token_count; //dummy value just so that it compiles...
}

void print_token_list(int num, string commands[])
{
    cout << "Number of tokens: " << num <<endl;
    for (int k = 0; k < num; k++)
    {
        cout << "token: " << commands[k] << "\t";
    }
    cout << endl;
}
