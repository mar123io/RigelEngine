#pragma once

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SFML/Graphics.hpp>

class GameObject
{
public:
	GameObject(float x, float y, sf::Color color);
	virtual ~GameObject();
	virtual void handleInput() = 0;
	virtual void update() = 0;
	virtual void render(sf::RenderWindow& window);
	sf::FloatRect getBounds() const;

	sf::Shape* getShape() const;

protected:
	sf::Shape* shape;
	float speed;
};

#endif // !GAMEOBJECT_H
