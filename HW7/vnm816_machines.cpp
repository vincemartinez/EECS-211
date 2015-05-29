#include <iostream>
#include <stdlib.h>
#include <string>

#include "machines.h"

//*****************************************//
// node class functions

node::node(string n, IPAddress a) {
    name = new string;
    *name = n;
    my_address = a;
}

node::~node() {
    delete name;
}

void node::display() {
    
    cout << "   Name: " << *name << "   IP address: ";
    my_address.display();
}

int node::amIThisComputer(IPAddress a) {
    if(my_address.sameAddress(a))
        return 1;
    else
        return 0;
}

int node::myType() {
    return 0;
}

//*****************************************//
// laptop class functions

laptop::laptop(string n, IPAddress a) : node(n,a)  {
    incoming = outgoing = NULL;
    my_server.parse("0.0.0.0");
}

void laptop::display() {
    
    cout << "Laptop computer:  ";
    node::display();
    
    if(my_server.isNULL()) {
        cout << "\n    Not connected to any server.\n";
    }
    else {
        cout << "\nConnected to ";
        my_server.display();
        cout << "\n";
    }
    
    cout << "\n   Incoming datagram:  ";
    if(incoming==NULL) cout << "No datagram.";
    else               {cout << "\n";  incoming->display(); }
    
    cout << "\n   Outgoing datagram:  ";
    if(outgoing==NULL) cout << "No datagram.";
    else               {cout << "\n"; outgoing->display(); }
    
}

int laptop::myType() {
    return LAPTOP;
}

void laptop::initiateDatagram(datagram* d) {
    outgoing = d;
}

void laptop::receiveDatagram(datagram* d) {
    incoming = d;
}

int laptop::canAcceptConnection(int machine_type){

	if (my_server.isNULL()&&(machine_type==SERVER)){
		return 1;
	}

	else return 0;

}

void laptop::connect(IPAddress x, int machine_type){

	if (machine_type == SERVER){

		my_server = x;

	}

}

void laptop::transferDatagram(){

	extern node* network[MAX_MACHINES];

	if (outgoing != NULL&&!my_server.isNULL()){

		for (int i = 0; i < MAX_MACHINES; i++){

			if (network[i] == NULL){
				break;
			}

			if (network[i]->amIThisComputer(my_server)){

				network[i]->receiveDatagram(outgoing);
				outgoing = NULL;
				break;

			}

		}

	}

}


//*****************************************//
// server class functions

server::server(string n, IPAddress a) : node(n,a)  {
    number_of_laptops = number_of_wans = 0;
    dlist = new msg_list; /**********new*********/
}

void server::display() {
    int i;
    
    cout << "Server computer:  ";
    node::display();
    
    cout << "\n   Connections to laptops: ";
    if(number_of_laptops==0) cout << "    List is empty.";
    else for(i=0; i<number_of_laptops; i++) {
        cout << "\n      Laptop " << i+1 << ":   ";
        laptop_list[i].display();
    }
    cout << "\n\n   Connections to WANs:    ";
    if(number_of_wans==0) cout << "    List is empty.";
    else for(i=0; i<number_of_wans; i++) {
        cout << "\n         WAN " << i+1 << ":   ";
        WAN_list[i].display();
    }
    
    cout << "\n\n   Message list:\n";
    dlist->display();
    
    cout << "\n\n";
    
}

int server::myType() {
    return SERVER;
}

int server::canAcceptConnection(int machine_type){

	if (machine_type == WAN_MACHINE){

		for (int i = 0; i < 4; i++){

			if (WAN_list[i].isNULL()){

				return 1;

			}

		}

	}

	else if (machine_type == LAPTOP){

		for (int j = 0; j < 8; j++){

			if (laptop_list[j].isNULL()){

				return 1;

			}

		}

	}

	return 0;

}

void server::connect(IPAddress x, int machine_type){

	if (machine_type == LAPTOP){

		for (int i = 0; i < 8; i++){

			if (laptop_list[i].isNULL()){
				
				number_of_laptops++;
				laptop_list[i] = x;
				break;

			}

		}

	}

	else if (machine_type == WAN_MACHINE){

		for (int j = 0; j < 4; j++){

			if (WAN_list[j].isNULL()){

				number_of_wans++;
				WAN_list[j] = x;
				break;

			}

		}

	}

}

void server::receiveDatagram(datagram* d) {
	dlist->append(d);
}


//*****************************************//
// WAN class functions

WAN::WAN(string n, IPAddress a) : node(n,a)  {
    number_of_servers = number_of_wans = 0;
    dlist = new msg_list; /**********new*********/
}

void WAN::display() {
    int i;
    
    cout << "WAN computer:  ";
    node::display();
    
    cout << "\n   Connections to servers: ";
    if(number_of_servers==0) cout << "    List is empty.";
    else for(i=0; i<number_of_servers; i++) {
        cout << "\n      Server " << i+1 << ":   ";
        server_list[i].display();
    }
    cout << "\n\n   Connections to WANs:    ";
    if(number_of_wans==0) cout << "    List is empty.";
    else for(i=0; i<number_of_wans; i++) {
        cout << "\n         WAN " << i+1 << ":   ";
        WAN_list[i].display();
    }
    
    cout << "\n\n   Message list:\n";
    dlist->display();
    
    cout << "\n\n";
    
}

int WAN::myType() {
    return WAN_MACHINE;
}

int WAN::canAcceptConnection(int machine_type){

	if (machine_type == WAN_MACHINE){

		for (int i = 0; i < 4; i++){

			if (WAN_list[i].isNULL()){

				return 1;

			}

		}

	}

	else if (machine_type == SERVER){

		for (int j = 0; j < 4; j++){

			if (server_list[j].isNULL()){

				return 1;

			}

		}

	}

	return 0;

}

void WAN::connect(IPAddress x, int machine_type){

	if (machine_type == SERVER){

		for (int i = 0; i < 4; i++){

			if (server_list[i].isNULL()){

				number_of_servers++;
				server_list[i] = x;
				break;

			}

		}

	}

	else if (machine_type == WAN_MACHINE){

		for (int j = 0; j < 4; j++){

			if (WAN_list[j].isNULL()){

				number_of_wans++;
				WAN_list[j] = x;
				break;

			}

		}

	}

}


void WAN::receiveDatagram(datagram* d) {
	dlist->append(d);
}
