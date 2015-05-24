#ifndef DATAGRAM
#define DATAGRAM

#include <iostream>
#include <string>

#include "definitions.h"

using namespace std;

class IPAddress {
	private:
		unsigned int a[4];
	
	public:
        IPAddress();    
		int parse(string);
		void display();
		int	sameAddress(IPAddress x);
};


class datagram {
	private:
		IPAddress src, dest;
		int length;
		string msg;
	
	public:
		void makeDatagram(IPAddress s, IPAddress d, string m);
		void display();
};


#endif