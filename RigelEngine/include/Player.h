#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

class Player
{
public:
	Player(float x, float y);
	void handleInput();
	void update();
	void render(sf::RenderWindow& window);

private:
	sf::RectangleShape shape;
	float speed;
};

#endif // PLAYER_H
