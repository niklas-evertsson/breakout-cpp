#pragma once
#include "Actor.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

namespace App
{
	extern std::map<ActorType, std::string> texturePath;

	int GetWindowHeight();
	int GetWindowWidth();
	sf::Vector2i GetResolution();
	std::string GetFontPath();
	std::string GetHeartPath();
	std::string GetLevelPath();
	void Init();
	void Run();
};
