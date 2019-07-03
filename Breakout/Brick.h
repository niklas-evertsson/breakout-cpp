#pragma once
#include "Actor.h"
#include "BrickFactory.h"

class Brick : public Actor
{
public:
	Brick();
	static void RegisterFactoryType(const std::string& name, BrickFactory* factory);
	static Brick* Create(const std::string& name);

private:
	static std::map<std::string, BrickFactory*> factories;
};

class ArmouredBrick : public Brick
{
public:
	ArmouredBrick();
};

class ExplosiveBrick : public Brick
{
public:
	ExplosiveBrick();
	void TakeDamage();
};

class InvisibleBrick : public Brick
{
public:
	InvisibleBrick();
	void TakeDamage();

private:
	sf::Color visibleColor = sf::Color().Magenta;
};

class MetalBrick : public Brick
{
public:
	MetalBrick();
	void TakeDamage();

private:
	int health = 3;
	int alphaStep = 255 / health;
};

class NormalBrick : public Brick
{
public:
	NormalBrick();
	void TakeDamage();
};
