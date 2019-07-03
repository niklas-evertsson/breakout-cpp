#include "GameData.h"

namespace GameData
{
	GameState state = GameState::waitingForStart;
}

GameState GameData::GetState()
{
	return state;
}

void GameData::SetState(GameState newState)
{
	state = newState;
}
