#pragma once
#include <SFML/Graphics.hpp>
#include "Tile.h"

class Board
{
public:
	Board();
	void draw(sf::RenderWindow& window);

	void initilaize(float cols, float rows);

	~Board();

private:

	void scale();
	void initilaizeTiles();

	sf::Sprite m_background;
	std::vector<Tile> m_tiles;
	float m_cols;
	float m_rows;
};