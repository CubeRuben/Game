#pragma once
#include <string>
#include "SFML/Graphics.hpp"

class GraphicsData
{
public:
	const int countOfTextures = 1;
	const std::string paths[1] = { 
		"assets/blocks/stone.png" 
	};

	sf::Texture* textures = new sf::Texture[countOfTextures];
	sf::Sprite* sprites = new sf::Sprite[countOfTextures];

	GraphicsData();

	void loadTextures();

	void setSprites();
};

