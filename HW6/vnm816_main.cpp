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
int node_count = 0;
int i = 0;
int j = 0;
int machine_deleted = 0;

int main() {
    string* cmd_line = new string;
    string* parsed_command = new string[MAX_TOKENS_ON_A_LINE];
    int  number_of_tokens;
    int  done;
    
    int cmd;
    int ec1, ec2, error_code;
    IPAddress ip1, ip2;
    datagram d;

    // Determine and set up source of input.
    if(COMMANDS_FROM_FILE) {
        (*inp).open("p6input.txt", ios::in);
        if(!(*inp)) {
            cout << "***Could not open file.";
            return 0;
        }
    }
    
    fillSystemCommandList();

	for (int i = 0; i < MAX_MACHINES; i++){
		network[i] = NULL;
	}
    
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
		switch (cmd) {
		case HALT:
			cout << "** Command HALT recognized" << endl;
			done = 1;
			break;
		case SYSTEM_STATUS:
			cout << "** Command SYSTEM_STATUS recognized" << endl;

			cout << "Nodes in the network:" << endl;

			for (j = 0; j < MAX_MACHINES; j++){

				if (network[j] != NULL){

					network[j]->display();
					cout << endl;

				}

				

			}
			cout << "End of network." << endl;

			break;
		case CREATE_MACHINE:
			cout << "** Command CREATE_MACHINE recognized" << endl;

			if (parsed_command[1] == "laptop"){

				IPAddress laptopIP;
				laptopIP.parse(parsed_command[3]);

				if (laptopIP.parse(parsed_command[3]) == BAD_IP_ADDRESS){
					error_code = BAD_IP_ADDRESS;
					break;
				}

				if (node_count == MAX_MACHINES){
					error_code = NETWORK_FULL;
					break;
				}

				for (i = 0; i < MAX_MACHINES; i++){

					if (network[i] == NULL){

						laptop * laptop_node = new laptop(parsed_command[2], laptopIP);
						network[i] = (node*)laptop_node;
						network[i]->display();
						node_count++;
						break;

					}

				}
				

			}



			else if (parsed_command[1] == "server"){

				IPAddress serverIP;
				serverIP.parse(parsed_command[3]);

				if (serverIP.parse(parsed_command[3]) == BAD_IP_ADDRESS){
					error_code = BAD_IP_ADDRESS;
					break;
				}

				if (node_count == MAX_MACHINES){
					error_code = NETWORK_FULL;
					break;
				}

				for (i = 0; i < MAX_MACHINES; i++){

					if (network[i] == NULL){

						server * server_node = new server(parsed_command[2], serverIP);
						network[i] = (node*)server_node;
						network[i]->display();
						node_count++;
						break;

					}

				}
				

			}



			else if (parsed_command[1] == "wan"){

				IPAddress wanIP;
				wanIP.parse(parsed_command[3]);

				if (wanIP.parse(parsed_command[3]) == BAD_IP_ADDRESS){
					error_code = BAD_IP_ADDRESS;
					break;
				}

				if (node_count == MAX_MACHINES){
					error_code = NETWORK_FULL;
					break;
				}

				for (i = 0; i < MAX_MACHINES; i++){

					if (network[i] == NULL){

						WAN * wan_node = new WAN(parsed_command[2], wanIP);
						network[i] = (node*)wan_node;
						network[i]->display();
						node_count++;
						break;

					}

				}
				

			}
			else error_code = UNKNOWN_MACHINE_TYPE;


			break;
		case DESTROY_MACHINE:
			cout << "** Command DESTROY_MACHINE recognized" << endl;

			for (j = 0; j < MAX_MACHINES; j++){

				IPAddress machineIP;
				machineIP.parse(parsed_command[1]);


				if (network[j] != NULL){

					if ((network[j])->amIThisComputer(machineIP)){
						delete network[j];
						network[j] = NULL;
						machine_deleted = 1;
						node_count--;
						cout << "Computer removed from the network." << endl;
					}

				}

			}

			if (machine_deleted == 0){
				error_code = NO_SUCH_MACHINE;
			}

			break;
		case CONNECT:
			cout << "** Command CONNECT recognized" << endl;
			break;
		case CHECK_CONNECTIONS:
			cout << "** Command CHECK_CONNECTIONS recognized" << endl;
			break;
		case DATAGRAM_CMD:
			cout << "** Command DATAGRAM recognized" << endl;
			ec1 = ip1.parse(parsed_command[1]);
			ec2 = ip2.parse(parsed_command[2]);
			if ((ec1 != 0) || (ec2 != 0))
				error_code = BAD_IP_ADDRESS;

			else {
				int datagram_created = 0;
				for (j = 0; j < MAX_MACHINES; j++){

					if (network[j] != NULL){

						int same = (*network[j]).amIThisComputer(ip1);

						if (same){

							datagram* node_datagram = new datagram;
							node_datagram->makeDatagram(ip1, ip2, parsed_command[3]);
							((laptop*)network[j])->initiateDatagram(node_datagram);
							node_datagram->display();
							cout << endl;
							datagram_created = 1;
							break;

						}

					}
					
				}

				if (datagram_created == 0){
					
					error_code = NO_SUCH_MACHINE;
					break;
				}

			}
			
                break;
            case CONSUME_DATAGRAM:
                cout << "** Command CONSUME_DATAGRAM recognized" << endl;
                break;
            case TIME_CLICK:
                cout << "** Command TIME_CLICK recognized" << endl;
                break;
            case UNDEFINED_COMMAND:
                cout << "***ERROR:  Unrecognized command" << endl;
                break;
        }
        
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

