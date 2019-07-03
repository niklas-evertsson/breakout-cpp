#pragma once
#include "Actor.h"
#include "BrickFactory.h"
#include "GameData.h"

class Brick : public Actor
{
public:
	Brick();
	static void RegisterFactoryType(const std::string& name, BrickFactory* factory);
	static Brick* Create(const std::string& name);

protected:
	int brickScore = 50;

private:
	static std::map<std::string, BrickFactory*> factories;
};

class ExplosiveBrick : public Brick
{
public:
	ExplosiveBrick();
	void TakeDamage();
};

class MetalBrick : public Brick
{
public:
	MetalBrick();
	void TakeDamage();

private:
	int health = 2;
	int alphaStep = 255 / health;
};

class NormalBrick : public Brick
{
public:
	NormalBrick();
	void TakeDamage();
	void Destroy() { GameData::AddScore(brickScore); }
};
