#pragma once
#ifndef BULLET_H
#define BULLET_H

#include <SFML/Graphics.hpp>
#include "GameObject.h"

class Bullet : public GameObject
{
public:
	Bullet(float x, float y, float angle);
	void handleInput() override;
	void update() override;
	void render(sf::RenderWindow& window) override;

private:
	float vx;
	float vy;
};

#endif // !BULLET_H
