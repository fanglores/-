#include "event.h"
#include <iostream>

Event ConsoleEvent::getEvent()
{
	char c;
	std::cout << "Enter event: ";
	std::cin >> c;

	if (c == '1') return Event::PRESSED_START;
	if (c == '0') return Event::PRESSED_STOP;
	if (c == 'q') return Event::EXIT;
	
	return Event::NONE;
}

Event TCPEvent::getEvent()
{
	std::cout << "[ERROR] TCP Event is not implemented!";
		
	return Event::NONE;
}
