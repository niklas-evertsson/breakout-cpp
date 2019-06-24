#include <SFML/Graphics.hpp>

int main()
{
	int windowHeight = 600;
	int windowWidth = 800;

	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Breakout", sf::Style::Close);
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch(event.type)
			{
				case sf::Event::Closed:
					window.close();
					break;
				case sf::Event::GainedFocus:
					// TODO: Unpause game
					break;
				case sf::Event::KeyPressed:
					switch(event.key.code)
					{
						case sf::Keyboard::Space:
							// TODO: Start game
							break;
						default:
							break;
					}
				case sf::Event::LostFocus:
					// TODO: Pause game
					break;
				default:
					break;
			}
		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}