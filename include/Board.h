#pragma once
#include <SFML/Graphics.hpp>
#include "Tile.h"

class Board
{
public:
	Board();
	void draw(sf::RenderWindow& window);

	void initilaize(float cols, float rows);
	void respond(sf::Vector2f mousePressed, sf::RenderWindow& window, char& symbol);

	~Board();

private:

	void scale();
	void initilaizeTiles();
	void saveBoard();
	void removeRobot();
	void updateTile(char symbol, int i);

	sf::Sprite m_background;
	std::vector<Tile> m_tiles;
	float m_cols;
	float m_rows;
};