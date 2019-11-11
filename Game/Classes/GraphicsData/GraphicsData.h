#pragma once
#include <string>
#include "SFML/Graphics.hpp"

class GraphicsData
{
public:
	const int imageCount = 1;
	//const int countOfShaders = 1;
	const std::string paths[1] = { 
		"assets/blocks/stone.png" 
	};

	sf::Image* images = new sf::Image[imageCount];
	//sf::Sprite* sprites = new sf::Sprite[countOfTextures];
	//sf::Shader* shaders = new sf::Shader[countOfShaders];

	GraphicsData();

	void loadImages();

	//void loadTextures();
	/*void loadShaders();
	void compileShaders();*/
	//void setSprites();
};

