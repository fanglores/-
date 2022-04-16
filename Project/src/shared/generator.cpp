#include "generator.h"

Generator::Generator() : state(GeneratorState::STOPPED) 
{
	//init code //???
}

int Generator::Start()
{
	try
	{
		state = GeneratorState::STARTING;

		//some starting operations here

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

		state = GeneratorState::STOPPED;
		return 0;
	}
	catch (...)
	{
		state = GeneratorState::ERROR;
		return -1;
	}
}

