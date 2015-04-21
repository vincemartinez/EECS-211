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

// write your definitions for the member functions of the IPAddress and
//     datagram classes here