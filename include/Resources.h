//================================ include =========================//
#pragma once

#include <SFML/Graphics.hpp>



class Resources
{
public:

	static Resources& getInstance() {
		static Resources instance;
		return instance;
	}
	
	std::vector<sf::Texture>& getGeneralTexture();
	std::vector<sf::Texture>& getGameObjectTexture();
	std::vector<sf::Texture>& gettoolBarTexture();


private:

	// Delete copy constructor and assignment operator
	Resources(const Resources&) = delete;
	Resources& operator=(const Resources&) = delete;
	Resources();

	void loadFromFile(std::vector<std::string> fileNames, std::vector<sf::Texture>& texture);

	std::vector<sf::Texture> m_generalTexture;
	std::vector<sf::Texture> m_gameObjectTexture;
	std::vector<sf::Texture> m_toolBarTexture;

};