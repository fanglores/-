#pragma once

enum class Event
{
	NONE,
	PRESSED_START,
	PRESSED_STOP,
	EXIT
};

class IEvent
{
public:
	virtual Event getEvent() = 0;
};

class ConsoleEvent : public IEvent
{
public:
	Event getEvent() override;
};

class TCPEvent : public IEvent
{
public:
	Event getEvent() override;
};

