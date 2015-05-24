#include <iostream>
#include <stdlib.h>
#include <string>

#include "machines.h"

//*****************************************//
// node class functions

node::node(string n, IPAddress a){
	
	my_address = a;
	name = new string;
	*name = n;
}

node::~node(){
	delete name;
}


int node::amIThisComputer(IPAddress a){
	return my_address.sameAddress(a);
}

int node::myType(){
	return 0;
}

void node::display() {
    
    cout << "   Name: " << *name << "   IP address: ";
	my_address.display();
    
}

//*****************************************//
// laptop class functions

laptop::laptop(string n, IPAddress a) : node(n,a){
	
	this->incoming = NULL;
	this->outgoing = NULL;

	my_server.parse("0.0.0.0");

}


void laptop::initiateDatagram(datagram* d){
	outgoing = d;
}


void laptop::receiveDatagram(datagram* d){
	incoming = d;
}

int laptop::myType(){
	return LAPTOP;
}

void laptop::display() {
    
    cout << "Laptop computer:  ";
    node::display();
    
    cout << "\n   Incoming datagram:  ";
    if(incoming==NULL) cout << "No datagram.";
    else               {cout << "\n";  incoming->display(); }
    
    cout << "\n   Outgoing datagram:  ";
    if(outgoing==NULL) cout << "No datagram.";
    else               {cout << "\n"; outgoing->display(); }
    
}

//*****************************************//
// server class functions


server::server(string n, IPAddress a) : node(n,a){
	//cout << "ay3" << endl;
	this->number_of_laptops = 0;
	this->number_of_wans = 0;
}

int server::myType(){
	return SERVER;
}

void server::display(){
    
    cout << "Server computer:  ";
    node::display();
    
    cout << "\n   Connections to laptops: ";
    cout << "List is empty.";
    cout << "\n   Connections to WANs:    ";
    cout << "List is empty.";
    cout << endl;
    
}

//*****************************************//
// WAN class functions

WAN::WAN(string n, IPAddress a) :node(n, a){
	this->number_of_servers = 0;
	this->number_of_wans = 0;
}

int WAN::myType(){
	return WAN_MACHINE;
}

void WAN::display() {
    
    cout << "WAN computer:  ";
    node::display();
    
    cout << "\n   Connections to laptops: ";
    cout << "List is empty.";
    cout << "\n   Connections to WANs:    ";
    cout << "List is empty.";
    cout << endl;
    
}