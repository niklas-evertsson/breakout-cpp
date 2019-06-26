#pragma once
#include "Actor.h"

class Ball : public Actor
{
public:
	Ball();

	void Update(float deltaTime);

protected:
	bool HitWall();
	float radius;
};
