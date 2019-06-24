#include <string>
#include <SFML/Graphics.hpp>

class Actor
{
public:
	Actor() {};
	Actor(std::string imagePath);

	sf::Sprite* GetSprite()
	{
		return &sprite;
	}

	virtual void Update(){}
	void SetSprite(std::string imagePath);

private:
	sf::Sprite sprite;
};