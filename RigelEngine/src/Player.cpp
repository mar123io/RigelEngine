#include "Player.h"

Player::Player(float x, float y)
{
	shape.setSize(sf::Vector2f(50.0f, 50.0f));
	shape.setFillColor(sf::Color::Green);
	shape.setPosition(x, y);
	speed = 200.0f; // Pixels per second
}

void Player::handleInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		shape.move(0, -speed * 0.016f); // Move up
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		shape.move(0, speed * 0.016f); // Move down
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		shape.move(-speed * 0.016f, 0); // Move left
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		shape.move(speed * 0.016f, 0); // Move right
	}
}

void Player::update()
{
	// Update player state here
}

void Player::render(sf::RenderWindow& window)
{
	window.draw(shape);
}