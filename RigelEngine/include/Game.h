#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <vector>

#pragma once

#include "GameObject.h"
#include "Player.h"
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

	sf::RenderWindow window;
	std::vector<GameObject*> gameObjects;
};

#endif // !GAME_H