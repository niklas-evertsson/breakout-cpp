#include "Brick.h"
#include "BrickFactory.h"
#include "Game.h"

ArmouredBrickFactory::ArmouredBrickFactory()
{
	Brick::RegisterFactoryType("Armoured", this);
}
Brick* ArmouredBrickFactory::Create()
{
	return new ArmouredBrick();
}
static ArmouredBrickFactory armouredBrickFactory;

ExplosiveBrickFactory::ExplosiveBrickFactory()
{
	Brick::RegisterFactoryType("Explosive", this);
}
Brick* ExplosiveBrickFactory::Create()
{
	return new ExplosiveBrick();
}
static ExplosiveBrickFactory explosiveBrickFactory;

InvisibleBrickFactory::InvisibleBrickFactory()
{ 
	Brick::RegisterFactoryType("Invisible", this);
}
Brick* InvisibleBrickFactory::Create()
{
	return new InvisibleBrick();
}
static InvisibleBrickFactory invisibleBrickFactory;

MetalBrickFactory::MetalBrickFactory()
{
	Brick::RegisterFactoryType("Metal", this);
}
Brick* MetalBrickFactory::Create()
{
	return new MetalBrick();
}
static MetalBrickFactory metalBrickFactory;

NormalBrickFactory::NormalBrickFactory()
{
	Brick::RegisterFactoryType("Normal", this);
}
Brick* NormalBrickFactory::Create()
{
	return new NormalBrick();
}
static NormalBrickFactory normalBrickFactory;
