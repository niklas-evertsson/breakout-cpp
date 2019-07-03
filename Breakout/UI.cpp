#include "App.h"
#include "GameData.h"
#include "UI.h"

UI::UI(sf::RenderWindow& window) : window(window)
{
	font.loadFromFile(App::GetFontPath());
	gameOverText.setFont(font);
	gameOverText.setCharacterSize(gameOverTextSize);

	instructionsText.setFont(font);
	instructionsText.setCharacterSize(startTextSize);
	instructionsText.setFillColor(sf::Color::White);

	scoreText.setFont(font);
	scoreText.setCharacterSize(scoreTextSize);
	scoreText.setString(scoreString);
	scoreText.setFillColor(sf::Color::White);
	scoreText.setPosition(scorePadding, scorePadding);

	startText.setFont(font);
	startText.setCharacterSize(startTextSize);
	startText.setFillColor(sf::Color::White);

	texture.loadFromFile(App::GetHeartPath());
	playerLife.setTexture(texture);
	playerLife.setColor(sf::Color().Red);
}

void UI::Draw()
{
	sf::FloatRect textRect;

	DrawLives();
	DrawScore();

	if (GameData::GetState() == GameState::waitingForStart || GameData::GetState() == GameState::betweenGames)
	{
		startText.setString(startString);
		textRect = startText.getLocalBounds();
		startText.setOrigin(textRect.left + textRect.width * 0.5f, textRect.top);
		startText.setPosition((float)App::GetResolution().x * 0.5f, App::GetResolution().y * 0.5f + 100.0f);
		window.draw(startText);
	}

	if(GameData::GetState() == GameState::waitingForStart)
	{
		instructionsText.setString(controlsString);
		textRect = instructionsText.getLocalBounds();
		instructionsText.setOrigin(textRect.left + textRect.width * 0.5f, textRect.top);
		instructionsText.setPosition((float)App::GetResolution().x * 0.5f, App::GetResolution().y * 0.5f + 100.0f + textRect.height * 2 + startPadding);
		window.draw(instructionsText);

		instructionsText.setString(normalBlockDescription);
		textRect = instructionsText.getLocalBounds();
		instructionsText.setOrigin(textRect.left + textRect.width * 0.5f, textRect.top);
		instructionsText.setPosition((float)App::GetResolution().x * 0.5f, instructionsText.getPosition().y + textRect.height * 2 + startPadding);
		window.draw(instructionsText);

		instructionsText.setString(metalBlockDescription);
		textRect = instructionsText.getLocalBounds();
		instructionsText.setOrigin(textRect.left + textRect.width * 0.5f, textRect.top);
		instructionsText.setPosition((float)App::GetResolution().x * 0.5f, instructionsText.getPosition().y + textRect.height + startPadding);
		window.draw(instructionsText);

		instructionsText.setString(explosiveBlockDescription);
		textRect = instructionsText.getLocalBounds();
		instructionsText.setOrigin(textRect.left + textRect.width * 0.5f, textRect.top);
		instructionsText.setPosition((float)App::GetResolution().x * 0.5f, instructionsText.getPosition().y + textRect.height + startPadding);
		window.draw(instructionsText);
	}
	else if (GameData::GetState() == GameState::endGame)
	{
		gameOverText.setFillColor(endGameColor);
		gameOverText.setString(endGameString);
		textRect = gameOverText.getLocalBounds();
		gameOverText.setOrigin(textRect.left + textRect.width * 0.5f, textRect.top);
		gameOverText.setPosition((float)App::GetResolution().x * 0.5f, 100.0f);
		window.draw(gameOverText);
	}
	else if(GameData::GetState() == GameState::gameOver)
	{
		gameOverText.setFillColor(gameOverColor);
		gameOverText.setString(gameOverString);
		textRect = gameOverText.getLocalBounds();
		gameOverText.setOrigin(textRect.left + textRect.width * 0.5f, textRect.top);
		gameOverText.setPosition((float)App::GetResolution().x * 0.5f, 100.0f);
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
