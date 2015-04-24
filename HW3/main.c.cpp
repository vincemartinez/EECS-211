#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>

#include "definitions.h"
#include "system_utilities.h"
#include "datagram.h"

using namespace std;


int main() {

	int success;
	IPAddress ip1, ip2, ip3, ip4, ip5, ip6, ip7, ip8, ip9, ip10;
	IPAddress ips[10] = { ip1, ip2, ip3, ip4, ip5, ip6, ip7, ip8, ip9, ip10 };
	string ips_data[10] = { "1.2.3.4", "255.255.255.0", "0.0.0.255", "1.2.3.4", "255.255.255.0", "0.0.0.0", "256.1.1.1", "0.300.378.1", "1.2.3.512", "2.2.2.4" };
	datagram datagram;
	int i = 0;
	int error_code;

	for (i = 0; i < 10; i++){

		error_code=ips[i].parse((string)ips_data[i]);
		ips[i].display();

		if (error_code == BAD_IP_ADDRESS){
			printError(error_code);
		}

	}

	wait();

	int j = 0;
	int k = 0;
	int l = 0;

	for (j = 0; j < 9; j ++ ){
		for (k = j+1; k < 10; k++){
			if (ips[j].sameAddress(ips[k])){
				ips[j].display();
				cout << "is the same as ";
				ips[k].display();
				cout << "bitch." << endl;
			}
		}
	}

	datagram.makeDatagram(ips[0], ips[1], "Datagram 1");
	datagram.display();
	datagram.makeDatagram(ips[2], ips[3], "This is a test.");
	datagram.display();
	datagram.makeDatagram(ips[4], ips[5], "Dear Mom and Dad:");
	datagram.display();


}

