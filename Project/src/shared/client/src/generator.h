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

class IGenerator
{
protected:
	Client* commandExchanger;
	GeneratorState state;
public:
	IGenerator(Client* cr);
	virtual int getCommand() = 0;
	virtual int sendState() const = 0;
};

class Generator : public IGenerator
{
public:
	Generator();
	int getCommand();
	int sendState() const;
};
