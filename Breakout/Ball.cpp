#include "Actor.h"
#include "App.h"
#include "Ball.h"

Ball::Ball() : Actor(ActorType::Ball)
{
	SetColor(sf::Color().White);
	SetOrigin(GetSize() / 2.0f);
	sf::Vector2f startPosition = (sf::Vector2f)App::GetResolution() / 2.0f;
	startPosition.y += 50;
	SetPosition(startPosition);
	this->radius = std::max(GetSize().x, GetSize().y) / 2.0f;
	this->velocity = sf::Vector2f(200, -100);
}

void Ball::OnCollision(Actor& other)
{
	sf::Vector2f topLeft = other.GetPosition();
	sf::Vector2f bottomRight = topLeft + other.GetSize();

	if(posX + radius >= topLeft.x) // Left side
	{
		posX = topLeft.x - radius;
		velocity.x = -velocity.x;
		other.TakeDamage();
	}
	else if(posX - radius <= bottomRight.x) // Right side
	{
		posX = bottomRight.x + radius;
		velocity.x = -velocity.x;
		other.TakeDamage();
	}
	else if (posY + radius >= topLeft.y) // Top side
	{
		posY = topLeft.y - radius;
		velocity.y = -velocity.y;
		other.TakeDamage();
	}
	else if (posY - radius <= bottomRight.y) // Bottom side
	{
		posY = bottomRight.y - radius;
		velocity.y = -velocity.y;
		other.TakeDamage();
	}
}

void Ball::Update(float deltaTime)
{
	posX = GetPosX();
	posY = GetPosY();
	WallCollision();
	Move(velocity * deltaTime);
}


void Ball::WallCollision()
{
	if (posX - radius <= 0) // Left wall
	{
		posX = radius;
		velocity.x = -velocity.x;
	}
	else if (posX + radius >= App::GetWindowWidth()) // Right wall
	{
		posX = App::GetWindowWidth() - radius;
		velocity.x = -velocity.x;
	}

	if (posY - radius <= 0) //Top wall
	{
		posY = radius;
		velocity.y = -velocity.y;
	}

	else if (posY + radius >= App::GetWindowHeight()) //Bottom
	{
		// Destroy ball
	}

	SetPosition(posX, posY);

}
