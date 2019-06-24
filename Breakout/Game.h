#include <list>
#include "Actor.h"

class Game
{
public:
	Game(int sizeX, int sizeY);

	void AddActor(Actor* actor);
	void Draw(sf::RenderWindow &window);
	void Update();

private:
	int sizeX;
	int sizeY;
	std::list<Actor*> actors;
};