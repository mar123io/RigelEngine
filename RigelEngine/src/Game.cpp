#include <iostream>

#include "Game.h"

Game::Game() : window(sf::VideoMode(800, 600), "Asteroids")
{
	window.setFramerateLimit(60);
	spaceship = new Spaceship(400.0f, 300.0f);
	gameObjects.push_back(spaceship);
	gameObjects.push_back(new Asteroid(100.0f, 100.0f, 30.0f));
	gameObjects.push_back(new Asteroid(500.0f, 200.0f, 40.0f));
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
	checkCollisions();
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

void Game::checkCollisions()
{
	for (size_t i = 0; i < gameObjects.size(); ++i)
	{
		for (size_t j = i + 1; j < gameObjects.size(); ++j)
		{
			if (checkCollision(*gameObjects[i], *gameObjects[j]))
			{
				// Handle collision (e.g., stop movement, remove objects, etc.)
				std::cout << "Collision detected between objects " << i << " and " << j << "!" << std::endl;
			}
		}
	}
}