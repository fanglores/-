#include "system.h"

System::System() : state(SystemState::OFF) {}

int System::switchGenerator()
{	
	//add return values
	GeneratorState cs = generator.getState();
	if(cs == GeneratorState::STOPPED) generator.Start();
	else if(cs == GeneratorState::RUNNING) generator.Stop();
	else if(cs == GeneratorState::ERROR) std::cerr << "[ERROR] Generator error" << std::endl;
	else std::cerr << "[WARNING] Generator isn`t ready" << std::endl;
}

//full coverage is ready
int System::TurnOn()
{
	if (state == SystemState::WORKING)
	{
		std::cerr << "[WARNING] System is already turned on" << std::endl;
		return 0;
	}

	if (state == SystemState::ERROR) return -1;

	if (state == SystemState::OFF)
	{
		try
		{
			state = SystemState::STARTING;

			/* start code */

			state = SystemState::WORKING;
			return 0;
		}
		catch (...)
		{
			state = SystemState::ERROR;
			std::cerr << "[ERROR] System starting procedure fault" << std::endl;
			return -1;
		}
	}
	else 
	{
		std::cerr << "[ERROR] System is not ready. Code: " << int(state) << std::endl;
		return 1;
	}
}

//full coverage is ready
int System::TurnOff() 
{
	if (state == SystemState::OFF)
	{
		std::cerr << "[WARNING] System is already turned off" << std::endl;
		return 0;
	}

	if (state == SystemState::ERROR) return -1;

	if (state == SystemState::WORKING)
	{
		try
		{
			state = SystemState::STOPPING;

			/* stop code */

			state = SystemState::OFF;
			return 0;
		}
		catch (...)
		{
			state = SystemState::ERROR;
			std::cerr << "[ERROR] System stopping procedure fault" << std::endl;
			return -1;
		}
	}
	else 
	{
		std::cerr << "[ERROR] System is not ready. Code: " << int(state) << std::endl;
		return 1;
	}
}

int System::updatePhoto()
{
	try
	{
		previousPhoto = currentPhoto;
		currentPhoto = camera.getPhoto();

		return 0;
	}
	catch(...)
	{
		std::cerr << "[ERROR] System updatePhoto() fault" << std::endl;
		return -1;
	}	
}

