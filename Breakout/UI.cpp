#include "App.h"
#include "GameData.h"
#include "UI.h"

UI::UI(sf::RenderWindow& window) : window(window)
{
	font.loadFromFile(App::GetFontPath());
	gameOverText.setFont(font);
	gameOverText.setString("GAME OVER");
	gameOverText.setFillColor(sf::Color::Red);
	sf::FloatRect textRect = gameOverText.getLocalBounds();
	gameOverText.setOrigin(textRect.left + textRect.width * 0.5f, textRect.top);
	gameOverText.setPosition((float)App::GetResolution().x * 0.5f, App::GetResolution().y * 0.5f - 100.0f);

	startText.setFont(font);
	startText.setString("PRESS START TO PLAY");
	startText.setFillColor(sf::Color::White);
	textRect = startText.getLocalBounds();
	startText.setOrigin(textRect.left + textRect.width * 0.5f, textRect.top);
	startText.setPosition((float)App::GetResolution().x * 0.5f, App::GetResolution().y * 0.5f + 100.0f);

	texture.loadFromFile(App::GetHeartPath());
	playerLife.setTexture(texture);
	playerLife.setColor(sf::Color().Red);
}

void UI::Draw()
{
	if (GameData::GetState() == GameState::waitingForStart || GameData::GetState() == GameState::betweenGames)
	{
		window.draw(startText);
	}

	sf::Vector2f position(0.0f, 0.0f);
	for(int i = 0; i < PlayerData::GetLives(); i++)
	{
		playerLife.setPosition(position);
		window.draw(playerLife);
		position.x += playerLife.getGlobalBounds().width + lifePadding;
	}

	if (PlayerData::GetLives() <= 0)
	{
		window.draw(gameOverText);
	}
}
