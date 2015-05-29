#include "definitions.h"
#include "datagram.h"

#include <stdlib.h>
#include <string> 

using namespace std;

IPAddress::IPAddress() {
    for(int i = 0; i < 4; i++)
    {
        a[i] = 0;
    }
}

int IPAddress::parse(string s) {
	
	int i, j;
    unsigned int tmp;
	
    j = 0;
	for(i=0; i<4; i++) {
		tmp = 0;
		while ( (s[j]>='0') && (s[j]<='9') )
            tmp = 10*tmp + (s[j++]-'0');
		if(tmp<256)
            a[i] = tmp;
		else  //we found a bad IP addy part, so 0 them all out, return error
        {
            for (int k = 0; k < 4; k++)
            {
                a[k] = 0;
            }
            return BAD_IP_ADDRESS;
        }
		j++;
	}
	
	return 0;
}

void IPAddress::display() {
	
	cout << a[0] << "." << a[1] << "." << a[2] << "." << a[3];
}

int IPAddress::sameAddress(IPAddress x) {
	if(a[0]!=x.a[0]) return 0;
	if(a[1]!=x.a[1]) return 0;
	if(a[2]!=x.a[2]) return 0;
	if(a[3]!=x.a[3]) return 0;
	return 1;
}

/**************************new*************************/
int IPAddress::isNULL() {
    if(a[0]!=0) return 0;
    if(a[1]!=0) return 0;
    if(a[2]!=0) return 0;
    if(a[3]!=0) return 0;
    return 1;
}
/**************************new*************************/

void datagram::makeDatagram(IPAddress s, IPAddress d, string m) {
	src = s;
	dest = d;
    msg = m;
    length = m.length();
}


void datagram::display() {
	cout << "SOURCE: ";
	src.display();
	cout << "\nDESTINATION: ";
	dest.display();
	cout << "\nLENGTH: " << length;
	cout << "\nMESSAGE: \"" << msg << "\"\n\n";
}
