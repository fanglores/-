#include "generator.h"

#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

Generator::Generator() : state(GeneratorState::STOPPED) 
{	
  sock = socket(AF_INET, SOCK_DGRAM, 0);

  addr.sin_family = AF_INET;
  addr.sin_port = htons(3425);
  addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
}

Generator::~Generator()
{
	close(sock);
}

int Generator::sendCommand(const char* cmd)
{
	return sendto(sock, cmd, sizeof(cmd), 0, (struct sockaddr *)&addr, sizeof(addr));
}

GeneratorState Generator::getState() const
{
	return state;
}

int Generator::Start()
{
	try
	{
		state = GeneratorState::STARTING;

		//some starting operations here
		sendCommand("1");

		state = GeneratorState::RUNNING;
		return 0;
	}
	catch(...)
	{
		state = GeneratorState::ERROR;
		return -1;
	}
}

int Generator::Stop()
{
	try
	{
		state = GeneratorState::STOPPING;

		//some stop operations here
		sendCommand("0");

		state = GeneratorState::STOPPED;
		return 0;
	}
	catch (...)
	{
		state = GeneratorState::ERROR;
		return -1;
	}
}

