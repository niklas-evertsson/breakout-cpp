#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

sf::Vector2i GetResolution();
float DeltaTime();
float ElapsedTime();
int GetWindowHeight();
int GetWindowWidth();
void Init();
void Run();
void Tick();
