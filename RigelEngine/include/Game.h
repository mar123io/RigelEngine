#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <vector>

#pragma once

#include <SFML/Graphics.hpp>

#include "GameObject.h"
#include "Spaceship.h"
#include "Asteroid.h"
#include "Collision.h"

class Game
{
public:
	Game();
	void run();

private:
	void processEvents();
	void update();
	void render();
	void checkCollisions();
	void spawnAsteroids();

	sf::RenderWindow window;
	Spaceship* spaceship;
	std::vector<GameObject*> gameObjects;
	sf::Clock spawnClock;
};

#endif // !GAME_H