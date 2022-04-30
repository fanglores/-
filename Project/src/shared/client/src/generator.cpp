#include "generator.h"

IGenerator::IGenerator(Client* cr) : commandExchanger(cr), state(GeneratorState::STOPPED)
{}

Generator::Generator(Client* cr) : commandExchanger(cr), state(GeneratorState::STOPPED)
{}

int Generator::getCommand()
{
	char* cmd = commandExchanger->Receive();

	//process command

	return 0;
}

int Generator::sendState() const
{
	return commandExchanger->Send(int(state));
}
