#pragma once
#include "Actor.h"

class Ball : public Actor
{
	using Actor::Actor;

public:
	void Init();
	void OnCollision(Actor* other);
	void Update(float deltaTime);

protected:
	float radius = 0.0f;
	void WallCollision();
};
