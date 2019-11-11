#include <iostream>
#include <SFML/Graphics.hpp>

#include "Classes/Settings/Settings.h"
#include "Classes/GraphicsData/GraphicsData.h"
#include "Classes/Server/Server.h"

int main() 
{
	Settings settings;

	sf::Font font;
	font.loadFromFile("assets/fonts/overloader.ttf");
	sf::Text text("Alpha 0.0.1", font, 40);
	text.setPosition(0, -30);

	std::cout << "Creating window" << std::endl;
	sf::RenderWindow window(sf::VideoMode(settings.getSettings(settings.WINDOW_WIDTH), settings.getSettings(settings.WINDOW_HEIGHT)), "Game", sf::Style::Close);
	window.setFramerateLimit(60);
	std::cout << "Created window" << std::endl; 

	GraphicsData graphicsData;
	graphicsData.loadImages();
	//graphicsData.loadTextures();
	//graphicsData.setSprites();
	//graphicsData.loadShaders();

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
		window.draw(text);
		window.display();
	}

	return 0;
}