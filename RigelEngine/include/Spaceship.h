#pragma once

#ifndef SPACESHIP_H
#define SPACESHIP_H

#include <SFML/Graphics.hpp>
#include "GameObject.h"

class Spaceship : public GameObject
{
public:
	Spaceship(float x, float y);
	void handleInput() override;
	void update() override;
	void render(sf::RenderWindow& window) override;

	std::vector<sf::CircleShape> bullets;

private:
	float angle;
	sf::Clock bulletClock;
};

#endif // !SPACESHIP_H