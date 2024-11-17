#include "Player.h"

Player::Player(float x, float y) : GameObject(x, y, sf::Color::Green) {}

void Player::handleInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		shape->move(0, -speed * 0.016f); // Move up
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		shape->move(0, speed * 0.016f); // Move down
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		shape->move(-speed * 0.016f, 0); // Move left
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		shape->move(speed * 0.016f, 0); // Move right
	}
}

void Player::update()
{
	// Update player state here
}