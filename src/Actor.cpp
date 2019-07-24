#include "Actor.h"
#include "Game.h"

Actor::Actor(ActorType actorType)
{
	this->actorType = actorType;
	sprite.setTexture(Game::GetTexture(actorType));
}

void Actor::Destroy()
{
	TakeDamage();
	destroy = true;
}
