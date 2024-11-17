#pragma once
#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <vector>

#include "GameObject.h"
#include "Player.h"

class Game
{
public:
	Game();
	void run();

private:
	void processEvents();
	void update();
	void render();

	sf::RenderWindow window;
	std::vector<GameObject*> gameObjects;
};

#endif // !GAME_H