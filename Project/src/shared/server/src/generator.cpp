#include "generator.h"

#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

Generator::Generator(Client* ce) : commandExchanger(ce)
{	
  state = getState();
}

Generator::~Generator()
{
	close(sock);
}

GeneratorState Generator::getState() const
{
	char* buf = commandExchanger->Send("get state cmd");

	state = int(buf);
	return state;
}

int Generator::Start()
{
	try
	{
		state = GeneratorState::STARTING;

		//some starting operations here
		commandExchanger->Send("1");

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
		commandExchanger->Send("0");

		state = GeneratorState::STOPPED;
		return 0;
	}
	catch (...)
	{
		state = GeneratorState::ERROR;
		return -1;
	}
}

