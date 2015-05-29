#include <iostream>
#include <string>
#include <fstream>

#include "datagram.h"
#include "system_utilities.h"
#include "definitions.h"
#include "machines.h"


using namespace std;


ifstream* inp = new ifstream;
node* network[MAX_MACHINES];

int main() {
    string* cmd_line = new string;
    string* parsed_command = new string[MAX_TOKENS_ON_A_LINE];
    int  number_of_tokens;
    int  done;
    int cmd;
    int ec1, ec2, error_code;
    
    IPAddress ip1, ip2, ip3;
    string name = "";
    string type = "";
    int i;

	int machine_1_found=0;
	int machine_2_found=0;
	int machine_1=0;
	int machine_2=0;
    
    datagram* d2 = NULL;
    
    for (int i = 0; i < MAX_MACHINES; i++)
        network[i] = NULL;
    
    // Determine and set up source of input.
    if(COMMANDS_FROM_FILE) {
        (*inp).open("p7input.txt", ios::in);
        if(!(*inp)) {
            cout << "***Could not open file.";
            return 0;
        }
    }
    
    fillSystemCommandList();
    
    done = 0;
    
    do {
        error_code = 0;
        
        //Get command from input and parse into arg0 and argv
        if(COMMANDS_FROM_FILE)
            getline(*inp, *cmd_line);
        else {
            cout << ">";           // command line prompt
            getline(cin, *cmd_line);//, MAX_CMD_LINE_LENGTH);
        }
        number_of_tokens = parseCommandLine(*cmd_line, parsed_command);
        if(ECHO_COMMAND) print_token_list(number_of_tokens, parsed_command);
        
        cmd = getCommandNumber(parsed_command[0]);
        switch(cmd) {
            case HALT: {
                cout << "** Command HALT recognized" << endl;
                done = 1;
                break;
            }
            case SYSTEM_STATUS: {
                cout << "** Command SYSTEM_STATUS recognized" << endl;
                cout << "Nodes in the network:" << endl;
                for(i=0; i<MAX_MACHINES; i++) {
                    if(network[i]!=NULL) {
                        network[i]->display();
                        cout << endl;
                    }
                }
                cout << "End of network." << endl;
                break;
            }
            case CREATE_MACHINE: {
                cout << "** Command CREATE_MACHINE recognized" << endl;
                type = parsed_command[1];
                name = parsed_command[2];
                error_code = ip3.parse(parsed_command[3]);
                for (i = 0; i < MAX_MACHINES; i++)
                {
                    if (network[i] == NULL)
                        break;
                }
                
                if (i >= MAX_MACHINES) {
                    error_code = NETWORK_FULL;
                    break;
                }
                
                if (error_code == 0)
                {
                    if (parsed_command[1] == "laptop")
                        network[i] = new laptop(name, ip3);
                    else if (parsed_command[1] == "server")
                        network[i] = new server(name, ip3);
                    else if (parsed_command[1] == "wan")
                        network[i] = new WAN(name, ip3);
                    else
                        error_code = UNKNOWN_MACHINE_TYPE;
                    
                    if (error_code == 0)
                        network[i]->display();
                    
                    cout << endl;
                }
                break;
            }
            case DESTROY_MACHINE: {
                cout << "** Command DESTROY_MACHINE recognized" << endl;
                error_code = ip1.parse(parsed_command[1]);
                if(error_code!=0) break;
                for(i=0; i<MAX_MACHINES; i++) {
                    if(network[i]==NULL) continue;
                    if(network[i]->amIThisComputer(ip1)) {
                        delete network[i];
                        network[i] = NULL;
                        cout << "Computer removed from the network." << endl;
                        break;
                    }
                }
                if(i>=MAX_MACHINES) error_code = NO_SUCH_MACHINE;
                break;
            }
            case CONNECT: {
                cout << "** Command CONNECT recognized" << endl;

				error_code = ip1.parse(parsed_command[1]);
				if (error_code != 0) break;
				error_code = ip2.parse(parsed_command[2]);
				if (error_code != 0) break;

				for (i = 0; i < MAX_MACHINES; i++){

					if (network[i] == NULL){
						break;
					}

					if (network[i]->amIThisComputer(ip1)){
						machine_1_found = 1;
						machine_1 = i;
					}

					if (network[i]->amIThisComputer(ip2)){
						machine_2_found = 1;
						machine_2 = i;
					}


				}

				if (machine_1_found == 0 || machine_2_found == 0){
					error_code = NO_SUCH_MACHINE;
					machine_1_found = 0;
					machine_2_found = 0;
					break;
				}

				

				else{

					if (!(network[machine_1]->canAcceptConnection(network[machine_2]->myType())) || !(network[machine_2]->canAcceptConnection(network[machine_1]->myType()))){
						error_code = CONNECTION_REFUSED;
						machine_1_found = 0;
						machine_2_found = 0;
						break;
					}

					network[machine_1]->connect(ip2, network[machine_2]->myType());
					network[machine_2]->connect(ip1, network[machine_1]->myType());
				}

				machine_1_found = 0;
				machine_2_found = 0;
                break;
            }
            case CHECK_CONNECTIONS: {
                cout << "** Command CHECK_CONNECTIONS recognized" << endl;
                break;
            }
            case DATAGRAM_CMD: {
                cout << "** Command DATAGRAM recognized" << endl;
                error_code = ip1.parse(parsed_command[1]);
                if(error_code!=0) break;
                for(i=0; i<MAX_MACHINES; i++) {
                    if(network[i]==NULL) continue;
                    if(network[i]->amIThisComputer(ip1)) {
                        break;
                    }
                }
                if(i>=MAX_MACHINES) {
                    error_code = NO_SUCH_MACHINE;
                    break;
                }
                ec1 = ip1.parse(parsed_command[1]);
                ec2 = ip2.parse(parsed_command[2]);
                if((ec1!=0) || (ec2!=0)) error_code = BAD_IP_ADDRESS;
                else {
                    d2 = new datagram;
                    d2->makeDatagram(ip1, ip2, parsed_command[3]);
                    d2->display();
                    ((laptop*)network[i])->initiateDatagram(d2);
                    cout << endl;
                }
                break;
            }
            case CONSUME_DATAGRAM: {
                cout << "** Command CONSUME_DATAGRAM recognized" << endl;
                break;
            }
            case TIME_CLICK: {
                cout << "** Command TIME_CLICK recognized" << endl;

				for (i = 0; i<MAX_MACHINES; i++){

					if (network[i] == NULL){
						break;
					}

					if (network[i]->myType() == LAPTOP){

						((laptop*)network[i])->transferDatagram();

					}

				}

                break;
            }
            case UNDEFINED_COMMAND: {
                cout << "***ERROR:  Unrecognized command" << endl;
                break;
            }
        }
        
        cout << endl;
        
        if(error_code!=0) printError(error_code);
        
        if(COMMANDS_FROM_FILE) wait();
    }
    while(!done);
    
    cout << "That's all, folks.";
    
    freeSystemCommandList(); //deletes the list of command elements
    delete[] parsed_command;
    delete cmd_line;
    delete inp;
    
    //the following deletes any machines that were not "destroyed"
    for (int i = 0; i < MAX_MACHINES; i++)
    {
        if (network[i] != NULL)
            delete network[i];
    }
}

