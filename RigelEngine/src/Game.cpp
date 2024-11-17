#include <iostream>

#include "Game.h"

Game::Game() : window(sf::VideoMode(800, 600), "Asteroids")
{
	window.setFramerateLimit(60);
	spaceship = new Spaceship(400.0f, 300.0f);
	gameObjects.push_back(spaceship);
	spawnAsteroids();
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

	if (spawnClock.getElapsedTime().asSeconds() > 2)
	{
		spawnAsteroids();
		spawnClock.restart();
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

void Game::spawnAsteroids()
{
	int numberOfAsteroids = 0;
	int asteroidCount = 0;
	for (auto& gameObject : gameObjects)
	{
		if (dynamic_cast<Asteroid*>(gameObject) != nullptr)
			asteroidCount++;
	}

	// Only spawn new asteroids if there are less than 3
	if(asteroidCount < 3)
		numberOfAsteroids = rand() % 2 + 2;

	for (int i = 0; i < numberOfAsteroids && asteroidCount < 3; ++i, ++asteroidCount)
	{
		float x = static_cast<float>(rand() % 800);
		float y = static_cast<float>(rand() % 600);
		float size = static_cast<float>(rand() % 40 + 20);
		gameObjects.push_back(new Asteroid(x, y, size));
	}
}