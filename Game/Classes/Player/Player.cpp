#include "Player.h"

Player::Player() 
{
	position.x = 0;
	position.y = 0;
	force.x = 0;
	force.y = 0;
	speed.x = 0;
	speed.y = 0;
	mass = 50;
	playerBody = sf::RectangleShape(sf::Vector2<float>(10, 20));
	playerBody.setFillColor(sf::Color::Green);
}

Player::Player(float x, float y) 
{
	position.x = 0;
	position.y = 0;
	force.x = 0;
	force.y = 0;
	speed.x = 0;
	speed.y = 0;
	mass = 50;
	playerBody = sf::RectangleShape(sf::Vector2<float>(10, 20));
	playerBody.setFillColor(sf::Color::Green);
}

/*Player::Player(sf::Vector2<float> startPosition) 
{
	position = startPosition;
}*/

void Player::step(World* world)
{
	force.x = 0;
	force.y = world->g * mass;

	for (int y = position.y / 16; y < position.y + force.x / mass * 1.f / 60.f + speed.x * 1.f / 60.f; y++)
	{
		if (world->getBlock(position.x / 16, y)) 
		{
			std::cout << "Work" << std::endl;
		}
	}
	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) 
	{
		position.y -= 1;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		position.y += 1;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		position.x -= 1;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		position.x += 1;
	}*/

	speed.x += force.x / mass * 1.f / 60.f;
	speed.y += force.y / mass * 1.f / 60.f;

	position.x += speed.x * 1.f / 60.f * 16;
	position.y += speed.y * 1.f / 60.f * 16;
}

void Player::draw(sf::RenderWindow* window, GraphicsData* graphicsData)
{
	playerBody.setPosition(sf::Vector2<float>(window->getSize().x / 2.f, window->getSize().y / 2.f));
	window->draw(playerBody);
}

sf::Vector2<float> Player::getPosition() 
{
	return position;
}