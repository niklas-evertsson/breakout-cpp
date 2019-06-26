#include "App.h"
#include "Ball.h"

Ball::Ball() : Actor("../resources/ball32.png")
{
	GetSprite()->setOrigin(GetSize() / 2.0f);
	SetPosition((sf::Vector2f)GetResolution() / 2.0f);
	radius = std::max(GetSize().x, GetSize().y) / 2.0f;
	velocity = sf::Vector2f(200, 250);
}

bool Ball::HitWall()
{
	bool hit = false;
	float posX = GetPosX();
	float posY = GetPosY();

	if(posX - radius <= 0) // Left wall
	{
		hit = true;
		posX = radius;
		velocity.x = -velocity.x;
	}
	else if(posX + radius >= GetWindowWidth()) // Right wall
	{
		hit = true;
		posX = GetWindowWidth() - radius;
		velocity.x = -velocity.x;
	}
	if (posY - radius <= 0) //Top wall
	{
		hit = true;
		posY = radius;
		velocity.y = -velocity.y;
	}
	else if (posY + radius >= GetWindowHeight()) //Bottom wall
	{
		hit = true;
		posY = GetWindowHeight() - radius;
		velocity.y = -velocity.y;
	}

	return hit;
}

void Ball::Update(float deltaTime)
{
	Move(velocity * deltaTime);
	HitWall();
}
