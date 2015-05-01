#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>

#include "definitions.h"
#include "system_utilities.h"

using namespace std;


int main() {
    
    ifstream inp;
    
    string cmd_line;
    string parsed_command[MAX_TOKENS_ON_A_LINE];
    int number_of_tokens;
    bool done;

    //COMMANDS_FROM_FILE is a constant set in definitions.h
    //If its value is 1, then main will read commands from file test.txt
    //If its value is 0, then main will read commands from the user (typed
    //    next to the command prompt >)
    if(COMMANDS_FROM_FILE) {
        inp.open("test.txt", ios::in);
        if(!inp) {
            cout << "***Could not open file.";
            return 0;
        }
    }
    
    int line_number = 1;
    
    do {
        if(COMMANDS_FROM_FILE) {
			getline(inp, cmd_line);
			
			if (cmd_line != "")
            {
                done = false; //we were able to get a line, so we're not done
            }
            else
            {
                done = true; //failed to get a line, so we're done
            }
        }
        else //commands will come from the user
        {
            cout << ">"; // display the command line prompt
            getline(cin, cmd_line); //get line of commands and store in cmd_line
            if (cmd_line != "")
            {
                done = false; //we got a line, so we're not done
            }
            else
            {
                done = true; //we got an empty line, so we're done
            }
        }

        if (!done) //we have a line to process
        {
			cout << "hey" << endl;
            //call the function that YOU define (parseCommandLine)
            number_of_tokens = parseCommandLine(cmd_line, parsed_command);
            if(ECHO_COMMAND) //if this value is 1, then we want to print it
                             // back to the user
            {
                cout << "Line Number: " << line_number << endl;
                print_token_list(number_of_tokens, parsed_command);
            }
            line_number++;
        }
    } while (!done);
}

