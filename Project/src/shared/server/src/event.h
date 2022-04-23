#pragma once

enum class Event
{
	NONE,
	PRESSED_START,
	PRESSED_STOP,
	EXIT,
	SWITCHGENERATOR
};

class IEvent
{
public:
	virtual Event getEvent();
	virtual char readEvent() = 0;
};

class ConsoleEvent : public IEvent
{
public:
	char readEvent() override;
};

class TCPEvent : public IEvent
{
public:
	char readEvent() override;
};

