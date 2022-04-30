#include "client.h"

#include <iostream>
using namespace std;

Client::~Client()
{
	delete[] buf;
}

UDPClient::UDPClient()
{
	sock = socket(AF_INET, SOCK_DGRAM, 0);

	addr.sin_family = AF_INET;
	addr.sin_port = htons(3425);
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
}

int UDPClient::Connect() const
{
	if(bind(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) 
	{
		cerr << "[ERROR] bind" << endl;
		return 1;
	}

	return 0;
}

char* UDPClient::Receive()
{
	bytes_read = recvfrom(sock, buf, MSG_SIZE, 0, NULL, NULL);
	buf[bytes_read] = '\0';
	
	return buf;
}

