#include "Brick.h"
#include "BrickFactory.h"
#include "Game.h"

ExplosiveBrickFactory::ExplosiveBrickFactory()
{
	Brick::RegisterFactoryType("Explosive", this);
}
Brick* ExplosiveBrickFactory::Create()
{
	return new ExplosiveBrick();
}
static ExplosiveBrickFactory explosiveBrickFactory;

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
