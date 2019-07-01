#include "App.h"
#include "Command.h"
#include "InputHandler.h"

Command::Command(InputHandler* inputHandler)
{
	this->inputHandler = inputHandler;
}

MoveXCommand::MoveXCommand(InputHandler* inputHandler) : Command(inputHandler) {}

void MoveXCommand::Execute(Actor* actor)
{
	float posX = std::max(0.0f, std::min(inputHandler->mousePosition.x, (float)App::GetResolution().x - actor->GetSize().x));
	actor->SetPosition(posX, actor->GetPosition().y);
}
