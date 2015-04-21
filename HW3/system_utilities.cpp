// This file contains functions used at the system and main level.

#include <iostream>
#include <string>

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
		

