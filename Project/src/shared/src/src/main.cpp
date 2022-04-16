#include "system.h"
#include "event.h"
#include "camera.h"
#include "generator.h"

//***********************************main.cpp*********************************
int main()
{   
	std::cout << "Hello, docker!!!" << std::endl;

	System solauticSystem;
	IEvent* eventReceiver = new ConsoleEvent();
	Event event = Event::NONE;

	while (event != Event::EXIT)
	{
		event = eventReceiver->getEvent();

		switch(event)
		{
			case (Event::PRESSED_START):
				std::cerr << "[INFO] Starting the machine" << std::endl;
				solauticSystem.TurnOn();
				break;

			case (Event::PRESSED_STOP):
				std::cerr << "[INFO] Stopping the machine" << std::endl;
				solauticSystem.TurnOn();
				break;

			case (Event::EXIT):
				std::cerr << "[EXIT]" << std::endl;
				std::cerr << "[EXIT] Stopping the machine" << std::endl;
				solauticSystem.TurnOff();
				std::exit(0);
				break;

			default:
				std::cerr << "[ERROR] Unknown event!" << std::endl;
		}
	}
	
    return 0;
}
