#pragma once
#include <string>
#include <SFML/Graphics.hpp>

class Actor
{
public:
	Actor() {};
	Actor(std::string imagePath);

	sf::Sprite* GetSprite(){return &sprite;}
	virtual void Update(float deltaTime){};
	void Move(float dx, float dy){sprite.move(dx, dy);}
	void SetSprite(std::string imagePath);

private:
	sf::Sprite sprite;
	sf::Vector2f velocity;
};
