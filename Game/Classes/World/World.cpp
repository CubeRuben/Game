#include "World.h"
#include "../GraphicsData/GraphicsData.h"

#include <iostream>
#include <SFML/Graphics.hpp>

World::World() 
{
	worldSize.x = 0;
	worldSize.y = 0;

	g = 9.81f;

	generateArray();
}

World::World(int size_x, int size_y) 
{
	this->worldSize.x = size_x;
	this->worldSize.y = size_y;

	g = 9.81f;

	generateArray();
}

World::World(sf::Vector2<int> worldSize)
{
	this->worldSize = worldSize;

	g = 9.81f;

	generateArray();
}

int World::getBlock(int x, int y)
{
	return gridOfBlocks[(x + worldSize.x) % worldSize.x][y % worldSize.y];
}

void World::setBlock(sf::Vector2<int> position, int id)
{
	gridOfBlocks[(position.x + worldSize.x) % worldSize.x][position.y % worldSize.y] = id;
}

void World::generateWorld(unsigned int seed)
{
	std::cout << "Generating world with seed: " << seed << std::endl;
	srand(seed);
	int startY = 10;
	for (int x = 0; x < worldSize.x; x++)
	{
		startY += rand() % 3 - 1;
		for (int y = startY; y < worldSize.y; y++)
		{
			setBlock(sf::Vector2<int>(x, y), 1);
		}
	}
	std::cout << "World generated" << std::endl;
}

void World::step()
{

}

void World::draw(sf::RenderWindow* window, GraphicsData* graphicsData, sf::Vector2<float> cameraPosition)
{
	for (int x = 0; x < worldSize.x; x++)
	{
		for (int y = 0; y < worldSize.y; y++)
		{
			int id = getBlock(x, y);
			id--;
			if (id != -1)
			{
				graphicsData->sprites[id].setPosition(x * 16 - cameraPosition.x + window->getSize().x / 2, y * 16 - cameraPosition.y + window->getSize().y / 2);
				window->draw(graphicsData->sprites[id]);
			}
		}
	}
}

void World::generateArray() 
{
	gridOfBlocks = new int* [worldSize.x];
	for (int i = 0; i < worldSize.x; i++)
	{
		gridOfBlocks[i] = new int[worldSize.y];
	}

	for (int x = 0; x < worldSize.x; x++)
	{
		for (int y = 0; y < worldSize.y; y++)
		{
			gridOfBlocks[x][y] = 0;
		}
	}
}
