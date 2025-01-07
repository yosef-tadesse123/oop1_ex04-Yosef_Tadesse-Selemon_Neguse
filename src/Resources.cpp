
#include "Resources.h"
#include <iostream>

//--------------------------------------- Constructor ------------------------------------------------
// Loads textures from files and initializes the resources.
Resources::Resources() {

	std::vector<std::string> fileNames{ "Background.png", "Tile.png", "Menu.png"};
	loadFromFile(fileNames, m_generalTexture);


	fileNames = {"Door.png","Wall.png", "Rock.png", "Robot.png", "Enemy.png"};
	loadFromFile(fileNames, m_gameObjectTexture);


	fileNames = { "Eraser.png", "Trash.png", "Save.png", "Hover.png", "HoverErase.png"};
	loadFromFile(fileNames, m_toolBarTexture);
}


//--------------------------------------- loadFromFile ------------------------------------------------
// Loads textures from the specified file names into the provided texture vector.
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
//--------------------------------------- getGeneralTexture ------------------------------------------------
// Returns a reference to the vector of general textures.
std::vector<sf::Texture>& Resources::getGeneralTexture() {

	return m_generalTexture;
}
//--------------------------------------- getGameObjectTexture ------------------------------------------------
// Returns a reference to the vector of game object textures
std::vector<sf::Texture>& Resources::getGameObjectTexture() {

	return m_gameObjectTexture;
}
//--------------------------------------- getToolBarTexture ------------------------------------------------
// Returns a reference to the vector of toolbar textures.
std::vector<sf::Texture>& Resources::gettoolBarTexture() {

	return m_toolBarTexture;
}