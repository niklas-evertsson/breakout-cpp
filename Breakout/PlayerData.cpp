#include "PlayerData.h"

namespace PlayerData
{
	int startLives = 3;
	int currentLives = startLives;
}

int PlayerData::GetLives()
{
	return currentLives;
}

void PlayerData::LoseLife()
{
	PlayerData::currentLives--;
}

void PlayerData::ResetLives()
{
	currentLives = startLives;
}
