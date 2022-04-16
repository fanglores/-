#include "system.h"
#include "event.h"
#include "camera.h"
#include "generator.h"

//***********************************main.cpp*********************************
int main()
{   
	std::cout << "Hello, docker!!!" << std::endl;

	MainMachine pc;
	Event event = Event::NONE;

	while (event != Event::EXIT)
	{
		event = getEvent();

		switch(event)
		{
			case (Event::PRESSED_START):
				std::cerr << "[INFO] Starting the machine" << std::endl;
				pc.Run();
				break;

			case (Event::PRESSED_STOP):
				std::cerr << "[INFO] Stopping the machine" << std::endl;
				pc.Stop();
				break;

			case (Event::EXIT):
				std::cerr << "[EXIT]" << std::endl;
				std::exit(0);
				break;

			default:
				std::cerr << "[ERROR] Unknown event!" << std::endl;
		}
	}
	
    return 0;
}
