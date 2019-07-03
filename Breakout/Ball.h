#pragma once
#include "Actor.h"

class Ball : public Actor
{
public:
	Ball();

	void OnCollision(Actor& other);
	void Update(float deltaTime, float elapsedTime);

protected:
	float radius = 0.0f;
	sf::Color color = sf::Color().White;
	void DamageActor(Actor& actor);
	void WallCollision();

private:
	enum DamageState
	{
		ready,
		startCooldown,
		isCoolingDown,
	};
	const float damageCooldownTime = 0.1f;
	float nextDamageTime = 0.0f;
	DamageState damageState;
};
