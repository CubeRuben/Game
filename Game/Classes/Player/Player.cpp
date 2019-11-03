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

	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::W)) && (speed.y == 0) && ((world->getBlock(position.x / 16, (position.y + 21) / 16) != 0) || (world->getBlock((position.x + 10) / 16, (position.y + 21) / 16) != 0)))
	{
		force.y -= 20000;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		force.y += 100;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		force.x -= 100;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		force.x += 100;
	}

	speed.x += force.x / mass * 1.f / 60.f;
	speed.y += force.y / mass * 1.f / 60.f;

	for (int y = (position.y + 20) / 16.f; y < (position.y + speed.y * (1.f / 60.f) * 16.f + 20.f) / 16.f; y++)
	{
		if ((world->getBlock((position.x + 9) / 16, y) != 0) || (world->getBlock(position.x / 16, y) != 0))
		{
			speed.y = 0;
			position.y = y * 16.f - 20.f;
			break;
		}
	}

	for (int x = (position.x + 10.f) / 16.f; x < (position.x + speed.x * (1.f / 60.f) * 16.f + 10.f) / 16.f; x++)
	{
		if ((world->getBlock(x, position.y / 16.f) != 0) || (world->getBlock(x, (position.y + 19.f) / 16.f) != 0))
		{
			speed.x = 0;
			position.x = x * 16.f - 10.f;
			break;
		}
	}

	for (int x = (position.x - 1.f) / 16.f; x > (position.x + speed.x * (1.f / 60.f) * 16.f) / 16.f - 1; x--)
	{
		if ((world->getBlock(x, position.y / 16.f) != 0) || (world->getBlock(x, (position.y + 19.f) / 16.f) != 0))
		{
			speed.x = 0;
			position.x = (x + 1) * 16.f;
			break;
		}
	}

	/*for (int y = position.x; y < position.y + speed.y * 1.f / 60.f + 20; y++)
	{
		if (world->getBlock((position.x + 10) / 16, y / 16) != 0)
		{
			speed.y = 0;
			position.y = y - 20;
			break;
		}

		if (world->getBlock(position.x / 16, y / 16) != 0)
		{
			speed.y = 0;
			position.y = y - 20;
			break;
		}
	}*/

	position.x += speed.x * (1.f / 60.f) * 16;
	position.y += speed.y * (1.f / 60.f) * 16;

	if (position.x < world->worldSize.x * 8.f) 
	{
		position.x += world->worldSize.x * 16.f;
	} 
	else if (position.x > world->worldSize.x * 24.f) 
	{
		position.x -= world->worldSize.y * 16.f;
	}

	//std::cout << position.x << " " << position.y << std::endl;
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