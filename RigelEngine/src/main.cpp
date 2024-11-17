#include <SFML/Graphics.hpp>

int main()
{
	// create the main window
	sf::RenderWindow window(sf::VideoMode(800, 600), "Rigel Engine");

	// Set the frame rate limit
	window.setFramerateLimit(60);

	// Main game loop
	while (window.isOpen())
	{
		// Process events
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		window.display();
	}

	return 0;
}