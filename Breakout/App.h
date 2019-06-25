#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

sf::RenderWindow* GetWindow();
sf::Vector2i GetResolution();
float DeltaTime();
float ElapsedTime();
void Init();
void Run();
void Tick();
