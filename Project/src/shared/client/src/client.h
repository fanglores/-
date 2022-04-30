#pragma once

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

const int MSG_SIZE = 1;

class Client
{
protected:
	int sock;
	struct sockaddr_in addr;
	char buf[MSG_SIZE];
	int bytes_read;
public:
	virtual int Connect() const = 0;
	virtual char* Receive() = 0;
	virtual ~Client();
};

class UDPClient : public Client
{
public:
	UDPClient();
	int Connect() const;
	char* Receive();
};

class TCPClient : public Client
{
public:
	TCPClient();
	int Connect() const;
	char* Receive();
};
