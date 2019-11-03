#include "GraphicsData.h"
#include <iostream>

GraphicsData::GraphicsData() 
{

}

void GraphicsData::loadTextures() 
{
	for (int i = 0; i < countOfTextures; i++) 
	{
		if (textures[i].loadFromFile(paths[i]))
		{
			std::cout << "File loaded from: " << paths[i] << std::endl;
		}
	}
}

/*void GraphicsData::loadShaders() 
{
	shaders[0].loadFromFile("assets/shaders/test.vert", "assets/shaders/test.frag");
}*/

void GraphicsData::setSprites()
{
	for (int i = 0; i < countOfTextures; i++) 
	{
		sprites[i].setTexture(textures[i]);
	}
}


