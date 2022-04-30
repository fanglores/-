#pragma once

#include "client.h"

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
	Client* commandExchanger;
	GeneratorState state;
public:
	Generator(Client* ce);
	~Generator();

	int Start();
	int Stop();

	GeneratorState getState();
};
