#include "App.h"
#include "Paddle.h"

Paddle::Paddle() : Actor(ActorType::Paddle)
{
	name = "Paddle";
	sf::Vector2f startPosition = sf::Vector2f((float)App::GetResolution().x / 2, (float)App::GetResolution().y - 50);
	SetPosition(startPosition);
}
