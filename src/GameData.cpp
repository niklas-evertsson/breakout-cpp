#include "GameData.h"

namespace GameData
{
	int totalScore = 0;
	GameState state = GameState::waitingForStart;
}

int GameData::GetScore()
{
	return totalScore;
}

void GameData::AddScore(int score)
{
	totalScore += score;
}

void GameData::ResetScore()
{
	totalScore = 0;
}

void GameData::SetState(GameState newState)
{
	state = newState;
}

GameState GameData::GetState()
{
	return state;
}
