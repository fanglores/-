#include "event.h"
#include <iostream>

Event IEvent::getEvent()
{
	char inputEvent = this->readEvent();

	if (inputEvent == '1') return Event::PRESSED_START;
	if (inputEvent == '0') return Event::PRESSED_STOP;
	if (inputEvent == 'q') return Event::EXIT;
	
	if (inputEvent == 'g') return Event::SWITCHGENERATOR;
	
	if (inputEvent == ' ') return Event::NONE;

	return Event::NONE;
}

char ConsoleEvent::readEvent()
{
	char c;
	std::cout << "Enter event: ";
	std::cin >> c;

	return c;
}

char TCPEvent::readEvent()
{
	std::cout << "[ERROR] TCP Event is not implemented!";
		
	return ' ';
}
