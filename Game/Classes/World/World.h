#pragma once
#include "../GraphicsData/GraphicsData.h"
#include <SFML/Graphics.hpp>

class World
{
public:
	int** gridOfBlocks = nullptr;
	sf::Vector2<int> worldSize;
	float g;

	World();
	World(int size_x, int size_y);
	World(sf::Vector2<int> worldSize);
	
	int getBlock(int x, int y);

	void generateWorld(unsigned int seed);
	void setBlock(sf::Vector2<int> position, int id);
	void step();
	void draw(sf::RenderWindow *window, GraphicsData* graphicsData, sf::Vector2<float> cameraPosition);
private:
	void generateArray();
}; 
