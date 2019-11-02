#include "Server.h"

Server::Server() 
{
	std::cout << "Creating server" << std::endl;
	player = Player(0, 0);
	world = World(100, 20);
}

void Server::step() 
{
	player.step(&world);
	world.step();
}

void Server::command(Server::ServerCommands cmd)
{
	std::cout << "Called command with id: " << ServerCommands::GENERATE_WORLD << std::endl;
	switch (cmd)
	{
	case GENERATE_WORLD:
		world.generateWorld(10);
		break;
	}
}

void Server::draw(sf::RenderWindow* window, GraphicsData* graphicsData) 
{
	player.draw(window, graphicsData);
	world.draw(window, graphicsData, player.getPosition());
}