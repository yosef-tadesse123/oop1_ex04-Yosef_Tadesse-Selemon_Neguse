
#include "Resources.h"
#include <iostream>

//constractor of resources file are loading files
Resources::Resources() {

	std::vector<std::string> fileNames{ "Background.png", "Tile.png", "Menu.png"};
	loadFromFile(fileNames, m_generalTexture);


	fileNames = {"Door.png","Wall.png", "Rock.png", "Robot.png", "Enemy.png"};
	loadFromFile(fileNames, m_gameObjectTexture);


	fileNames = { "Eraser.png", "Trash.png", "Save.png" };
	loadFromFile(fileNames, m_toolBarTexture);
}


//loadFromFile file function
void Resources::loadFromFile(std::vector<std::string> fileNames, std::vector<sf::Texture>& textures) {

	sf::Texture texture;
	for (int i = 0; i < fileNames.size(); i++)
	{
		if (!texture.loadFromFile(fileNames[i])) {
			exit(EXIT_FAILURE);
		}
		textures.push_back(texture);
	}
}

std::vector<sf::Texture>& Resources::getGeneralTexture() {

	return m_generalTexture;
}

std::vector<sf::Texture>& Resources::getGameObjectTexture() {

	return m_gameObjectTexture;
}

std::vector<sf::Texture>& Resources::gettoolBarTexture() {

	return m_toolBarTexture;
}