#pragma once

#include <netinet/in.h>

enum class GeneratorState
{
    STARTING,
	RUNNING,
    STOPPING,
    STOPPED,
	ERROR
};

class Generator
{
private:
	int sock;
  struct sockaddr_in addr;
    GeneratorState state;

	int sendCommand(const char* cmd);

public:
	Generator();
	~Generator();
    int Start();
    int Stop();
    GeneratorState getState() const;
};
