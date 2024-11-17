#include "GameObject.h"

GameObject::GameObject(float x, float y, sf::Color color)
{
	shape.setSize(sf::Vector2f(50.0f, 50.0f));
	shape.setFillColor(color);
	shape.setPosition(x, y);
	speed = 200.0f; // Default speed
}

void GameObject::render(sf::RenderWindow& window)
{
	window.draw(shape);
}

sf::FloatRect GameObject::getBounds() const
{
	return shape.getGlobalBounds();
}