#include "App.h"
#include "Command.h"
#include "GameData.h"
#include "InputHandler.h"
#include <iostream>

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

StartCommand::StartCommand(InputHandler* inputHandler) : Command(inputHandler) {}

void StartCommand::Execute(Actor* actor)
{
	if (GameData::GetState() == waitingForStart)
	{
		GameData::SetState(GameState::starting);
	}
	if (GameData::GetState() == betweenGames)
	{
		GameData::SetState(GameState::playing);
	}
}
