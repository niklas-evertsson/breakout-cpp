#pragma once

enum GameState
{
	waitingForStart,
	starting,
	playing,
	betweenGames,
	gameOver,
	endGame
};

namespace GameData
{
	int GetScore();
	void AddScore(int score);
	void ResetScore();
	void SetState(GameState newState);
	GameState GetState();
};

