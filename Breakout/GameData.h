#pragma once

enum GameState
{
	waitingForStart,
	starting,
	playing,
	betweenGames
};

namespace GameData
{
	GameState GetState();
	void SetState(GameState newState);
};

