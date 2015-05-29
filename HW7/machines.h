#ifndef MACHINES
#define MACHINES

#include "datagram.h"
#include "msg_list.h"

//*****************************************//
class node {
protected:
    string* 		name;
    IPAddress	my_address; 
public:
    node(string n, IPAddress a);
    ~node();
    virtual void display();
    int amIThisComputer(IPAddress a);
    virtual int myType();
    //**********new************//
    virtual int canAcceptConnection(int machine_type) = 0;
    virtual void connect(IPAddress x, int machine_type) = 0;
    virtual void receiveDatagram(datagram *d) = 0;
    //**********new************//
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
    //**********new************//
    int  canAcceptConnection(int machine_type);
    void connect(IPAddress x, int machine_type);
    void transferDatagram();
    //**********new************//
};
//*****************************************//

//*****************************************//
class server : public node {
protected:
    IPAddress	laptop_list[8];
    IPAddress	WAN_list[4];
    int		number_of_laptops;
    int		number_of_wans;
    //**********new************//
    msg_list* dlist;
    //**********new************//
    
public:
    server(string n, IPAddress a);
    void display();
    int myType();
    //**********new************//
    int  canAcceptConnection(int machine_type);
    void connect(IPAddress x, int machine_type);
    void receiveDatagram(datagram *d);
    //**********new************//

};
//*****************************************//

//*****************************************//
class WAN : public node {
protected:
    IPAddress	server_list[4];
    IPAddress	WAN_list[4];
    int		number_of_servers;
    int		number_of_wans;
    //**********new************//
    msg_list* dlist;
    //**********new************//
    
public:
    WAN(string n, IPAddress a);
    void display();
    int  myType();
    //**********new************//
    int  canAcceptConnection(int machine_type);
    void connect(IPAddress x, int machine_type);
    void receiveDatagram(datagram *d);
    //**********new************//
};
//*****************************************//

#endif
