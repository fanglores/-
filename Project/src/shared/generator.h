#pragma once

enum class GeneratorState
{
    STARTING,
	RUNNING,
    STOPPING,
    STOPPED,
	ERROR
};

class Generator
{
private:
    GeneratorState state;

public:
	Generator();
    int Start();
    int Stop();
};
