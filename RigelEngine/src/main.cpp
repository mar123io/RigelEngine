#include <SFML/Graphics.hpp>

#include "Player.h"

int main()
{
	// create the main window
	sf::RenderWindow window(sf::VideoMode(800, 600), "Rigel Engine");

	// Set the frame rate limit
	window.setFramerateLimit(60);

	// Create a Player
	Player player(375.0f, 275.0f); // Start position at the center of the window

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

		player.handleInput();

		player.update();

		window.clear();

		player.render(window);

		window.display();
	}

	return 0;
}