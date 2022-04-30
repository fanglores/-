#include "client.h"

//#include <unistd.h>
#include <iostream>
using namespace std;


int main()
{
  Client* cli = new UDPClient();

  while(1) 
  {
    cout << cli->Receive() << endl;
  }
}
