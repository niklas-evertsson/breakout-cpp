#pragma once
#include "Actor.h"
class InputHandler;

class Command
{
public:
	Command(InputHandler* inputHandler);
	virtual void Execute(Actor* actor) = 0;

protected:
	InputHandler* inputHandler = 0;
};

class MoveXCommand : public Command
{
public:
	MoveXCommand(InputHandler* inputHandler);
	virtual void Execute(Actor* actor);
};
