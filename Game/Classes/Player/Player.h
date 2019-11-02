#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "../World/World.h"
#include "../GraphicsData/GraphicsData.h"

class Player
{
private:
	sf::Vector2<float> position;
	sf::Vector2<float> force;
	sf::Vector2<float> speed;
	float mass;
	sf::RectangleShape playerBody;

public:
	
	Player();
	Player(sf::Vector2<float> startPosition);
	Player(float x, float y);

	void step(World* world);
	void draw(sf::RenderWindow* window, GraphicsData* graphicsData);
	
	sf::Vector2<float> getPosition();
};