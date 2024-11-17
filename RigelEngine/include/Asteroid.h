#pragma once
#ifndef ASTEROID_H
#define ASTEROID_H

#include <SFML/Graphics.hpp>

#include "GameObject.h"

class Asteroid : public GameObject
{
public:
	Asteroid(float x, float y, float size);
	void handleInput() override;
	void update() override;
	void render(sf::RenderWindow& window) override;

private:
	void createIrregularShape(float size);
	float angle;
	float size;
};

#endif // !ASTEROID_H
