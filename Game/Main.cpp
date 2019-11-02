#include <iostream>
#include <SFML/Graphics.hpp>

#include "Classes/GraphicsData/GraphicsData.h"
#include "Classes/Server/Server.h"

int main() 
{
	std::cout << "Creating window" << std::endl;
	sf::RenderWindow window(sf::VideoMode(800, 400), "Game", sf::Style::Close);
	window.setFramerateLimit(60);
	std::cout << "Created window" << std::endl; 

	GraphicsData graphicsData;
	graphicsData.loadTextures();
	graphicsData.setSprites();

	Server server;
	server.command(Server::ServerCommands::GENERATE_WORLD);

	while (window.isOpen())
	{
		server.step();

		sf::Event ev;
		while (window.pollEvent(ev))
		{
			if (ev.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		
		

		window.clear();
		server.draw(&window, &graphicsData);
		window.display();
	}

	return 0;
}