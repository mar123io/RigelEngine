#include "Game.h"

Game::Game() : window(sf::VideoMode(800, 600), "Rigel Engine")
{
	window.setFramerateLimit(60);
	gameObjects.push_back(new Player(375.0f, 275.0f)); // Add a player to the game objects
}

void Game::run()
{
	while (window.isOpen())
	{
		processEvents();
		update();
		render();
	}
}

void Game::processEvents()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
	}

	for (GameObject* gameObject : gameObjects)
	{
		gameObject->handleInput();
	}
}

void Game::update()
{
	for (GameObject* gameObject : gameObjects)
	{
		gameObject->update();
	}
}

void Game::render()
{
	window.clear();
	for (GameObject* gameObject : gameObjects)
	{
		gameObject->render(window);
	}
	window.display();
}