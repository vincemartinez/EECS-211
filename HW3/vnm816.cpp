#include "definitions.h"
#include "datagram.h"

#include <stdlib.h>
#include <string> 
#include <sstream>

using namespace std;

IPAddress::IPAddress() {
    for(int i = 0; i < 4; i++)
    {
        a[i] = 0;
    }
}

// write your definitions for the member functions of the IPAddress and
//     datagram classes here

int IPAddress::parse(string s) {

	istringstream strm;
	strm.str(s);

	int num_1;
	int num_2;
	int num_3;
	int num_4;
	char period;

	strm >> num_1 >> period >> num_2 >> period >> num_3 >> period >> num_4;
	if (num_1 <= 255 && num_1 >= 0 && num_2 <= 255 && num_2 >= 0 && num_3 <= 255 && num_3 >= 0 && num_4 <= 255 && num_4 >= 0){

		a[0] = num_1;
		a[1] = num_2;
		a[2] = num_3;
		a[3] = num_4;

		return(0);
	}

	else{
		return(BAD_IP_ADDRESS);
	}


}


void IPAddress::display(void){

	cout << a[0] << "." << a[1] << "." << a[2] << "." << a[3];

}


int IPAddress::sameAddress(IPAddress x){

	if (a[0] == x.a[0] && a[1] == x.a[1] && a[2] == x.a[2] && a[3] == x.a[3]){
		return(1);
	}

	else{
		return(0);
	}
	
}

void datagram::makeDatagram(IPAddress s, IPAddress d, string m){

	int i = 0;

	src = s;
	dest = d;
	msg = m;
	length = m.length();

}


void datagram::display(void){

	cout << "SOURCE: ";
	src.display();
	cout << endl;

	cout << "DESTINATION: ";
	dest.display();
	cout << endl;

	cout << "MESSAGE LENGTH: " << length << endl;

	cout << "MESSAGE: \"" << msg << "\"" << endl;

	cout << endl;

}
