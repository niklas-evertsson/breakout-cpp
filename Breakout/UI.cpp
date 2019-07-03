#include "App.h"
#include "GameData.h"
#include "UI.h"

UI::UI(sf::RenderWindow& window) : window(window)
{
	font.loadFromFile(App::GetFontPath());
	gameOverText.setFont(font);
	gameOverText.setCharacterSize(gameOverTextSize);

	scoreText.setFont(font);
	scoreText.setCharacterSize(21);
	scoreText.setString(scoreString);
	scoreText.setFillColor(sf::Color::White);
	scoreText.setPosition(scorePadding, scorePadding);

	startText.setFont(font);
	startText.setCharacterSize(startTextSize);
	startText.setString(startString);
	startText.setFillColor(sf::Color::White);
	sf::FloatRect textRect = startText.getLocalBounds();
	startText.setOrigin(textRect.left + textRect.width * 0.5f, textRect.top);
	startText.setPosition((float)App::GetResolution().x * 0.5f, App::GetResolution().y * 0.5f + 100.0f);

	texture.loadFromFile(App::GetHeartPath());
	playerLife.setTexture(texture);
	playerLife.setColor(sf::Color().Red);
}

void UI::Draw()
{
	DrawLives();
	DrawScore();

	if (GameData::GetState() == GameState::waitingForStart || GameData::GetState() == GameState::betweenGames)
	{
		window.draw(startText);
	}
	else if (GameData::GetState() == GameState::endGame)
	{
		gameOverText.setFillColor(endGameColor);
		gameOverText.setString(endGameString);
		sf::FloatRect textRect = gameOverText.getLocalBounds();
		gameOverText.setOrigin(textRect.left + textRect.width * 0.5f, textRect.top);
		gameOverText.setPosition((float)App::GetResolution().x * 0.5f, App::GetResolution().y * 0.5f - 100.0f);
		window.draw(gameOverText);
	}
	else if(GameData::GetState() == GameState::gameOver)
	{
		gameOverText.setFillColor(gameOverColor);
		gameOverText.setString(gameOverString);
		sf::FloatRect textRect = gameOverText.getLocalBounds();
		gameOverText.setOrigin(textRect.left + textRect.width * 0.5f, textRect.top);
		gameOverText.setPosition((float)App::GetResolution().x * 0.5f, App::GetResolution().y * 0.5f - 100.0f);
		window.draw(gameOverText);
	}
}

void UI::DrawLives()
{
	float spriteWidth = playerLife.getLocalBounds().width;
	sf::Vector2f position(App::GetWindowWidth() - spriteWidth - lifePadding, lifePadding);
	for(int i = 0; i < PlayerData::GetLives(); i++)
	{
		playerLife.setPosition(position);
		window.draw(playerLife);
		position.x -= spriteWidth + lifePadding;
	}
}

void UI::DrawScore()
{
	scoreText.setString(scoreString + std::to_string(GameData::GetScore()));
	window.draw(scoreText);
}
