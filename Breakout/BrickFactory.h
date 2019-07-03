#pragma once
class Brick;

class BrickFactory
{
public:
	virtual Brick* Create() = 0;
};

class ExplosiveBrickFactory : BrickFactory
{
public:
	ExplosiveBrickFactory();
	Brick* Create();
};

class MetalBrickFactory : BrickFactory
{
public:
	MetalBrickFactory();
	Brick* Create();
};

class NormalBrickFactory : BrickFactory
{
public:
	NormalBrickFactory();
	Brick* Create();
};

