#include "Actor.h"
#include "App.h"
#include "Ball.h"

Ball::Ball() : Actor(ActorType::Ball)
{
	name = "Ball";
	SetColor(sf::Color().White);
	SetOrigin(GetSize() * 0.5f);
	sf::Vector2f startPosition = (sf::Vector2f)App::GetResolution() * 0.5f;
	startPosition.y += 50;
	SetPosition(startPosition);
	this->radius = std::max(GetSize().x, GetSize().y) * 0.5f;
	this->velocity = sf::Vector2f(200, -600);
}

void Ball::OnCollision(Actor& other)
{
	sf::Vector2f topLeft = other.GetPosition();
	sf::Vector2f bottomRight = topLeft + other.GetSize();

	if(posX + radius >= topLeft.x) // Left side
	{
		velocity.x = -velocity.x;
		other.TakeDamage();
	}
	if(posX - radius <= bottomRight.x) // Right side
	{
		velocity.x = -velocity.x;
		other.TakeDamage();
	}
	if (posY + radius >= topLeft.y) // Top side
	{
		velocity.y = -velocity.y;
		other.TakeDamage();
	}
	if (posY - radius <= bottomRight.y) // Bottom side
	{
		velocity.y = -velocity.y;
		other.TakeDamage();
	}

	if (other.GetType() == ActorType::Paddle)
	{
		float paddleHalfSize = other.GetSize().x * 0.5f;
		float paddleCenter = other.GetPosition().x + paddleHalfSize;
		float collisionPoint = (posX - paddleCenter) / paddleHalfSize;
		float totalVelocity = sqrt(velocity.x * velocity.x + velocity.y * velocity.y);
		velocity.x = totalVelocity * collisionPoint;
		velocity.y = -sqrt(totalVelocity * totalVelocity - velocity.x * velocity.x);
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
	else if (posY - radius >= App::GetWindowHeight()) //Bottom
	{
		Destroy();
	}

	SetPosition(posX, posY);
}
