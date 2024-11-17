#include "Asteroid.h"

Asteroid::Asteroid(float x, float y, float size) : GameObject(x, y, sf::Color::Yellow), size(size)
{
	shape = new sf::CircleShape(size);
	sf::CircleShape* asteroidShape = static_cast<sf::CircleShape*>(shape);
	asteroidShape->setFillColor(sf::Color::Yellow);
	asteroidShape->setOrigin(size, size);
	angle = static_cast<float>(rand() % 360);
	speed = 50.0f;
}

void Asteroid::handleInput()
{
	// Asteroids move independently, no input required
}

void Asteroid::update()
{
	float radian = angle * (3.14159265f / 180.0f);
	shape->move(cos(radian) * speed * 0.016f, sin(radian) * speed * 0.016f);

	// Wrap around screen edges
	if (shape->getPosition().x < 0) shape->setPosition(800, shape->getPosition().y);
	if (shape->getPosition().x > 800) shape->setPosition(0, shape->getPosition().y);
	if (shape->getPosition().y < 0) shape->setPosition(shape->getPosition().x, 600);
	if (shape->getPosition().y > 600) shape->setPosition(shape->getPosition().x, 0);
}

void Asteroid::render(sf::RenderWindow& window)
{
	window.draw(*shape);
}