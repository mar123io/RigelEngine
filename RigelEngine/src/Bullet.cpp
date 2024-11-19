#include "Bullet.h"
#include <cmath>

Bullet::Bullet(float x, float y, float angle) : GameObject(x, y, sf::Color::White)
{
	shape = new sf::CircleShape(2.0f);
	shape->setFillColor(sf::Color::White);
	shape->setPosition(x, y);

	float radian = angle * (3.14159265f / 180.0f);
	vx = cos(radian) * 500.0f;
	vy = sin(radian) * 500.0f;
	speed = 500.0f;
}

void Bullet::handleInput()
{
	// Bullets move independently, no input required
}

void Bullet::update()
{
	shape->move(vx * 0.016f, vy * 0.016f);
}

void Bullet::render(sf::RenderWindow& window)
{
	window.draw(*shape);
}