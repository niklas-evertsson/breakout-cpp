#pragma once
#include "PlayerData.h"
#include <SFML/Graphics.hpp>

class UI
{
public:
	UI(sf::RenderWindow &window);
	virtual void Draw();

private:
	int lifePadding = 8;
	sf::Font font;
	sf::RenderWindow &window;
	sf::Sprite playerLife;
	sf::Text gameOverText;
	sf::Text startText;
	sf::Texture texture;
};

