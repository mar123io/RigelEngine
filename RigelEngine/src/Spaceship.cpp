#include "Spaceship.h"

Spaceship::Spaceship(float x, float y) : GameObject(x, y, sf::Color::White)
{
	shape = new sf::ConvexShape(3);
	sf::ConvexShape* spaceshipShape = static_cast<sf::ConvexShape*>(shape);
	spaceshipShape->setPoint(0, sf::Vector2f(0.0f, -20.0f));
	spaceshipShape->setPoint(1, sf::Vector2f(15.0f, 20.0f)); 
	spaceshipShape->setPoint(2, sf::Vector2f(-15.0f, 20.0f));  
	spaceshipShape->setFillColor(sf::Color::White);
	spaceshipShape->setPosition(x, y);
	spaceshipShape->setOrigin(0.0f, 0.0f);
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
		float radian = (angle - 90) * (3.14159265f / 180.0f);
		shape->move(cos(radian) * speed * 0.016f, sin(radian) * speed * 0.016f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		if (bulletClock.getElapsedTime().asSeconds() > 0.2f)
		{
			float bulletX = shape->getPosition().x + cos((angle - 90) * (3.14159265f / 180.0f)) * 20.0f;
			float bulletY = shape->getPosition().y + sin((angle - 90) * (3.14159265f / 180.0f)) * 20.0f;
			bullets.push_back(new Bullet(bulletX, bulletY, angle - 90));
			bulletClock.restart();
		}
	}
}

void Spaceship::update()
{
	for (auto it = bullets.begin(); it != bullets.end(); )
	{
		(*it)->update(); // update bullet position
		if ((*it)->getShape()->getPosition().x < 0 || (*it)->getShape()->getPosition().x > 800 ||
			(*it)->getShape()->getPosition().y < 0 || (*it)->getShape()->getPosition().y > 600)
		{
			delete* it;
			it = bullets.erase(it); // Remove bullets if out of screen bounds
		}
		else
		{
			++it;
		}
	}
}

void Spaceship::render(sf::RenderWindow& window)
{
	window.draw(*shape);
	for (auto& bullet : bullets)
	{
		bullet->render(window);
	}
}