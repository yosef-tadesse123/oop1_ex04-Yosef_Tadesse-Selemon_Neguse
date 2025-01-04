#pragma once
#include "Objects.h"


class Tile : public Objects
{
public:
	Tile(sf::Texture& texture);
	
	void setSprite(sf::Sprite& sprite);

	void draw(sf::RenderWindow& window);

	char getSymbol();
	void setIsEraseble(bool isEraseble);
	void setSymbol(char symbol);

	~Tile();

private:

	std::vector<sf::Sprite> m_theObjectsInTile;
	char m_symbol;
	bool m_isEraseble;
};