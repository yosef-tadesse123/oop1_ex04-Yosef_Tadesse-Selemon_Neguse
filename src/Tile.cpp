#pragma once
#include "Tile.h"
#include "Resources.h"

//--------------------------------------- Constructor ------------------------------------------------
// Initializes the tile with a texture, default symbol, and erase status.
Tile::Tile(sf::Texture& texture)
    : Objects(texture), m_symbol(' '), m_isEraseble(false)
{
    m_theObjectsInTile.push_back(sf::Sprite());
    m_theObjectsInTile.push_back(sf::Sprite(Resources::getInstance().gettoolBarTexture()[3]));
    m_theObjectsInTile.push_back(sf::Sprite(Resources::getInstance().gettoolBarTexture()[4]));
}

//--------------------------------------- draw ------------------------------------------------
// Draws the tile, its hover effect, and erase marker if applicable.
void Tile::draw(sf::RenderWindow& window)
{
    Objects::draw(window);
    window.draw(m_theObjectsInTile[0]);

    sf::Vector2f vector(sf::Mouse::getPosition(window));

    if (getSprite().getGlobalBounds().contains(vector)) {
        m_theObjectsInTile[1].setPosition(getSprite().getPosition());
        window.draw(m_theObjectsInTile[1]);
    }

    if (m_isEraseble)
    {
        m_theObjectsInTile[2].setPosition(getSprite().getPosition());
        window.draw(m_theObjectsInTile[2]);
    }
       

}
//--------------------------------------- setSprite ------------------------------------------------
// Updates the main sprite in the tile and its position.
void Tile::setSprite(sf::Sprite& sprite)
{
    m_theObjectsInTile[0] = sprite;
    m_theObjectsInTile[0].setPosition(getSprite().getPosition());

}
//--------------------------------------- setIsEraseble ------------------------------------------------
// Sets whether the tile is erasable.
void Tile::setIsEraseble(bool isEraseble)
{
    m_isEraseble = isEraseble;
}
//--------------------------------------- setSymbol ------------------------------------------------
// Sets the symbol representing the tile.
void Tile::setSymbol(char symbol)
{
    m_symbol = symbol;
}

//--------------------------------------- getSymbol ------------------------------------------------
// Returns the symbol representing the tile.
char Tile::getSymbol()
{
    return m_symbol;
}
//--------------------------------------- Destructor ------------------------------------------------
// Cleans up the tile's resources.
Tile::~Tile()
{
}