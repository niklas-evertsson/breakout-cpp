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
	this->velocity = sf::Vector2f(100, 500);
}

void Ball::DamageActor(Actor& actor)
{
	if (damageState == DamageState::ready)
	{
		actor.TakeDamage();
		damageState = DamageState::startCooldown;
	}
}

void Ball::OnCollision(Actor& other)
{
	sf::Vector2f topLeft = other.GetPosition();
	sf::Vector2f bottomRight = topLeft + other.GetSize();

	if(posX + radius >= topLeft.x) // Left side
	{
		velocity.x = -velocity.x;
		DamageActor(other);
	}
	if(posX - radius <= bottomRight.x) // Right side
	{
		velocity.x = -velocity.x;
		DamageActor(other);
	}
	if (posY + radius >= topLeft.y) // Top side
	{
		velocity.y = -velocity.y;
		DamageActor(other);
	}
	if (posY - radius <= bottomRight.y) // Bottom side
	{
		velocity.y = -velocity.y;
		DamageActor(other);
	}

	if (other.GetType() == ActorType::Paddle)
	{
		float paddleHalfSize = other.GetSize().x * 0.5f;
		float paddleCenter = other.GetPosition().x + paddleHalfSize;
		float collisionPoint = fmin((posX - paddleCenter) / paddleHalfSize, 0.9f);
		float totalVelocity = sqrt(velocity.x * velocity.x + velocity.y * velocity.y);
		velocity.x = totalVelocity * collisionPoint;
		velocity.y = -sqrt(abs(totalVelocity * totalVelocity - velocity.x * velocity.x));
	}
}

void Ball::Update(float deltaTime, float elapsedTime)
{
	if (damageState == DamageState::startCooldown)
	{
		nextDamageTime = elapsedTime + damageCooldownTime;
		damageState = DamageState::isCoolingDown;
	}
	else if (nextDamageTime > elapsedTime)
	{
		damageState = DamageState::ready;
	}
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
		destroy = true;
	}

	SetPosition(posX, posY);
}
