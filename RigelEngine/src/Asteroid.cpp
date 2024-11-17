#include "Asteroid.h"

Asteroid::Asteroid(float x, float y, float size) : GameObject(x, y, sf::Color::Yellow), size(size)
{
	createIrregularShape(size);
	shape->setPosition(x, y);
	angle = static_cast<float>(rand() % 360);
	speed = 50.0f;
}

void Asteroid::createIrregularShape(float size)
{
	shape = new sf::ConvexShape(8);
	sf::ConvexShape* asteroidShape = static_cast<sf::ConvexShape*>(shape);

	for (int i = 0; i < 8; ++i)
	{
		float angle = static_cast<float>(i) * 3.14159265f / 4.0f;
		float radius = size + static_cast<float>(rand() % 10 - 5);
		asteroidShape->setPoint(i, sf::Vector2f(std::cos(angle) * radius, sin(angle) * radius));
	}
	asteroidShape->setFillColor(sf::Color::Transparent);
	asteroidShape->setOutlineColor(sf::Color::Yellow);
	asteroidShape->setOutlineThickness(2.0f);
	asteroidShape->setOrigin(size, size);
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