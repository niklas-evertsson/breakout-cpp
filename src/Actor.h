#pragma once
#include <SFML/Graphics.hpp>

enum class ActorType
{
	Unknown,
	Ball,
	Brick,
	Paddle
};

class Actor
{
public:
	Actor() {};
	Actor(ActorType actorType);

	bool GetDestroy() { return destroy; }
	float GetPosX() { return sprite.getPosition().x; }
	float GetPosY() { return sprite.getPosition().y; }
	sf::Color GetColor() { return sprite.getColor(); }
	sf::FloatRect GetGlobalBounds() { return sprite.getGlobalBounds(); }
	sf::Sprite* GetSprite() { return &sprite; }
	sf::Vector2f GetPosition() { return sprite.getPosition(); }
	sf::Vector2f GetSize() { return sf::Vector2f(sprite.getLocalBounds().width, sprite.getLocalBounds().height); }
	std::string GetName() { return name; }
	void Destroy();
	void Move(sf::Vector2f deltaPosition) { sprite.move(deltaPosition); }
	void SetColor(sf::Color color) { sprite.setColor(color); }
	void SetOrigin(sf::Vector2f origin) { sprite.setOrigin(origin); }
	void SetPosition(float x, float y) { sprite.setPosition(x, y); }
	void SetPosition(sf::Vector2f position) { sprite.setPosition(position); }
	void SetScale(sf::Vector2f scale) { sprite.setScale(scale); }
	ActorType GetType() { return actorType; }

	virtual void TakeDamage() {};
	virtual void OnCollision(Actor& other) {}
	virtual void Update(float deltaTime, float elapsedTime) {}

protected:
	bool destroy = false;
	float posX = 0.0f;
	float posY = 0.0f;
	sf::Vector2f velocity;
	std::string name;
	ActorType actorType = ActorType::Unknown;

private:
	sf::Sprite sprite;
};
