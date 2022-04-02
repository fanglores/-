//#include <opencv2/opencv.hpp>
//#include "opencv2/core/utils/logger.hpp"
#include <iostream>

enum class Event
{
	NONE,
	PRESSED_START,
	PRESSED_STOP,
	EXIT
};

enum class SystemState
{
	STARTING,
	WORKING,
	STARTING_GENERATOR,
	STOPPING_GENERATOR,
	STOPPING,
	OFF,
	ERROR
};

enum class GeneratorState
{
    STARTING,
	RUNNING,
    STOPPING,
    STOPPED,
	ERROR
};

class Camera
{
private:
	//camera VideoCapture(0); //???
public:
	Camera()
	{}
	//cv::Mat getPhoto() {}
};

class Generator
{
private:
    GeneratorState state;

public:
	Generator() : state(GeneratorState::STOPPED) 
	{
		//init code //???
	}

    int Start()
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

    int Stop()
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
};

class MainMachine
{
private:
	SystemState state;

    Camera camera;
	Generator generator;

    //cv::Mat previousPhoto, currentPhoto;

	int Init()
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


public:
    MainMachine() : state(SystemState::OFF) {}

	int Run()
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

	int Stop() 
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

    void updatePhoto()
    {

    }
};

Event getEvent()
{
	char c;
	std::cout << "Enter event: ";
	std::cin >> c;

	if (c == '1') return Event::PRESSED_START;
	if (c == '0') return Event::PRESSED_STOP;
	if (c == 'q') return Event::EXIT;
	
	return Event::NONE;
}


int main()
{   
    //cv::utils::logging::setLogLevel(cv::utils::logging::LogLevel::LOG_LEVEL_SILENT);

	std::cout << "Hello, docker!!!" << std::endl;

	MainMachine pc;
	Event event = Event::NONE;

	while (event != Event::EXIT)
	{
		event = getEvent();

		switch(event)
		{
			case Event::PRESSED_START:
				std::cerr << "[INFO] Starting the machine" << std::endl;
				pc.Run();
				break;

			case Event::PRESSED_STOP:
				std::cerr << "[INFO] Stopping the machine" << std::endl;
				pc.Stop();
				break;

			case Event::EXIT:
				std::cerr << "[EXIT]" << std::endl;
				exit(0);
				break;

			default:
				std::cerr << "[ERROR] Unknown event!" << std::endl;
		}
	}
	
    return 0;
}
