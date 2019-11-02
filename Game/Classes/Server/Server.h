#pragma once

#include "../World/World.h"
#include "../Player/Player.h"
#include "../GraphicsData/GraphicsData.h"
#include <iostream>
#include <SFML/Graphics.hpp>

class Server 
{
private:
	World world;
	Player player;
public:
	enum ServerCommands
	{
		GENERATE_WORLD
	};

	Server();

	void step();
	void command(ServerCommands cmd);
	void draw(sf::RenderWindow* window, GraphicsData* graphicsData);
};