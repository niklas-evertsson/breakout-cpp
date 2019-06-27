#include "Actor.h"

Actor::Actor(sf::Texture* texture, ActorType actorType)
{
	this->actorType = actorType;
	sprite.setTexture(*texture);
}
