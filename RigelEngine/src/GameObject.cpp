#include "GameObject.h"

GameObject::GameObject(float x, float y, sf::Color color)
{
	shape = nullptr;
	speed = 200.0f; // Default speed
}

GameObject::~GameObject() 
{
	if (shape != nullptr) { delete shape; }
}

void GameObject::render(sf::RenderWindow& window)
{
	if(shape != nullptr)
		window.draw(*shape);
}

sf::FloatRect GameObject::getBounds() const
{
	return shape->getGlobalBounds();
}