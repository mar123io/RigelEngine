#include "Spaceship.h"

Spaceship::Spaceship(float x, float y) : GameObject(x, y, sf::Color::White)
{
	shape = new sf::ConvexShape(3);
	sf::ConvexShape* spaceshipShape = static_cast<sf::ConvexShape*>(shape);
	spaceshipShape->setPoint(0, sf::Vector2f(0.0f, -20.0f));
	spaceshipShape->setPoint(1, sf::Vector2f(10.0f, 10.0f));
	spaceshipShape->setPoint(2, sf::Vector2f(-10.0f, 10.0f));
	spaceshipShape->setFillColor(sf::Color::White);
	spaceshipShape->setPosition(x, y);
	angle = 0.0f;
	speed = 300.0f;
}

void Spaceship::handleInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		angle -= speed * 0.01f;
		shape->setRotation(angle);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		angle += speed * 0.01f;
		shape->setRotation(angle);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		float radian = angle * (3.14159265f / 180.0f);
		shape->move(cos(radian) * speed * 0.016f, sin(radian) * speed * 0.016f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		if (bulletClock.getElapsedTime().asSeconds() > 0.2f)
		{
			float radian = angle + (3.14159265f / 180.0f);
			sf::CircleShape bullet(2.0f);
			bullet.setFillColor(sf::Color::White);
			bullet.setPosition(shape->getPosition());
			bullets.push_back(bullet);
			bulletClock.restart();
		}
	}
}

void Spaceship::update()
{
	for (auto& bullet : bullets)
	{
		float radian = angle * (3.14159265f / 180.0f);
		bullet.move(cos(radian) * speed * 0.016f, sin(radian) * speed * 0.016f);
	}
}

void Spaceship::render(sf::RenderWindow& window)
{
	window.draw(*shape);
	for (auto& bullet : bullets)
	{
		window.draw(bullet);
	}
}