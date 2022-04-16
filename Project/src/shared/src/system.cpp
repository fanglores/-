#include "system.h"


int System::Init()
{
	try
	{
		state = SystemState::STARTING;

		//init camera, generator??

		state = SystemState::WORKING;
		std::cerr << "[INFO] Machine has successfully started" << std::endl;
		return 0;
	}
	catch (...)
	{
		state = SystemState::ERROR;
		std::cerr << "[ERROR] Machine initialisation error" << std::endl;
		return -1;
	}
}



System::System() : state(SystemState::OFF) {}

int System::Run()
{
	try 
	{
		switch (state)
		{
			case SystemState::OFF:
				std::cerr << "[INFO] Machine is starting" << std::endl;
				return Init();

			case SystemState::WORKING:
				std::cerr << "[WARNING] Machine is already running" << std::endl;
				return 0;

			default:
				std::cerr << "[ERROR] Machine is not ready" << std::endl;
				return -1;
		}
	}
	catch(...)
	{
			std::cerr << "[ERROR] Machine cannot run" << std::endl;
			return -1;
	}
}

int System::Stop() 
{
	if(state == SystemState::WORKING)
	{
		try
		{
			state = SystemState::STOPPING;

			/* code */

			state = SystemState::OFF;
			return 0;
		}
		catch (...)
		{
			std::cerr << "[ERROR] Machine cannot stop" << std::endl;
			return -1;
		}
	}
	else 
	{
		std::cerr << "[ERROR] Machine is not ready" << std::endl;
		return -1;
	}
}

void System::updatePhoto()
{}

