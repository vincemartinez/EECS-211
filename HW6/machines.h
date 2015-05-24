#ifndef MACHINES
#define MACHINES

#include "datagram.h"

//*****************************************//
class node {
protected:
    string* name;
    IPAddress	my_address; 
public:
    node(string n, IPAddress a);
    ~node();
    virtual void display();
    int amIThisComputer(IPAddress a);
    virtual int myType();
};
//*****************************************//

//*****************************************//
class laptop : public node {
protected:
    datagram* incoming;
    datagram* outgoing;
    IPAddress my_server;
    
public:
    laptop(string n, IPAddress a);
    void display();
    int  myType();
    void initiateDatagram(datagram* d);
    void receiveDatagram(datagram* d);
};
//*****************************************//

//*****************************************//
class server : public node {
protected:
    IPAddress	laptop_list[8];
    IPAddress	WAN_list[4];
    int		number_of_laptops;
    int		number_of_wans;
    
public:
    server(string n, IPAddress a);
    void display();
    int myType();
};
//*****************************************//

//*****************************************//
class WAN : public node {
protected:
    IPAddress	server_list[4];
    IPAddress	WAN_list[4];
    int		number_of_servers;
    int		number_of_wans;
    
public:
    WAN(string n, IPAddress a);
    void display();
    int  myType();
};
//*****************************************//

#endif
