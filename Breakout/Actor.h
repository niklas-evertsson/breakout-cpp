#pragma once
#include <string>
#include <SFML/Graphics.hpp>

class Actor
{
public:
	Actor() {};
	Actor(std::string imagePath);

	float GetPosX() { return sprite.getPosition().x; }
	float GetPosY() { return sprite.getPosition().y; }
	sf::Sprite* GetSprite() { return &sprite; }
	sf::Vector2f GetPosition() { return sprite.getPosition(); }
	sf::Vector2f GetSize() { return sf::Vector2f(sprite.getLocalBounds().width, sprite.getLocalBounds().height); }
	void Move(sf::Vector2f deltaPosition) { sprite.move(deltaPosition); }
	void SetPosition(float x, float y) { sprite.setPosition(x, y); }
	void SetPosition(sf::Vector2f position) { sprite.setPosition(position); }
	void SetSprite(std::string imagePath);

	virtual void Update(float deltaTime) {}

protected:
	sf::Vector2f velocity;

private:
	sf::Sprite sprite;
	sf::Texture texture;
};
