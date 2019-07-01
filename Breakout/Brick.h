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

protected:
	sf::Color color = sf::Color().Yellow;
};

class ExplosiveBrick : public Brick
{
public:
	ExplosiveBrick();
	void TakeDamage();

protected:
	sf::Color color = sf::Color().Red;
};

class InvisibleBrick : public Brick
{
public:
	InvisibleBrick();
	void TakeDamage();

protected:
	sf::Color color = sf::Color().Magenta;

private:
	sf::Color visibleColor = sf::Color().Magenta;
};

class MetalBrick : public Brick
{
public:
	MetalBrick();
	void TakeDamage();

protected:
	sf::Color color = sf::Color().Blue;

private:
	int health = 3;
	int alphaStep = 255 / health;
};

class NormalBrick : public Brick
{
public:
	NormalBrick();
	void TakeDamage();

protected:
	sf::Color color = sf::Color().White;
};
