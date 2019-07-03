#pragma once
#include "PlayerData.h"
#include <SFML/Graphics.hpp>

class UI
{
public:
	UI(sf::RenderWindow &window);
	virtual void Draw();

protected:
	void DrawLives();
	void DrawScore();

private:
	float scorePadding = 8.0f;
	float lifePadding = 8.0f;
	int gameOverTextSize = 28;
	int scoreTextSize = 21;
	int startTextSize = 28;
	sf::Color endGameColor = sf::Color::White;
	sf::Color gameOverColor = sf::Color::Red;
	sf::Font font;
	sf::RenderWindow &window;
	sf::Sprite playerLife;
	sf::Text gameOverText;
	sf::Text scoreText;
	sf::Text startText;
	sf::Texture texture;
	std::string gameOverString = "GAME OVER";
	std::string endGameString = "CONGRATULATIONS, YOU WIN";
	std::string scoreString = "SCORE: ";
	std::string startString = "PRESS START TO PLAY";
};

