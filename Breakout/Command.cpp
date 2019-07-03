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
	switch (GameData::GetState())
	{
	case GameState::waitingForStart:
		GameData::SetState(GameState::starting);
		break;
	case GameState::betweenGames:
		GameData::SetState(GameState::playing);
		break;
	case GameState::gameOver:
		GameData::SetState(GameState::waitingForStart);
		break;
	case GameState::endGame:
		GameData::SetState(GameState::waitingForStart);
		break;
	default:
		break;
	}
}
