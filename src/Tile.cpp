#pragma once
#include "Tile.h"
#include "Resources.h"

Tile::Tile(sf::Texture& texture)
    : Objects(texture), m_symbol(' '), m_isEraseble(false)
{
    m_theObjectsInTile.push_back(sf::Sprite());
    m_theObjectsInTile.push_back(sf::Sprite(Resources::getInstance().gettoolBarTexture()[3]));
    m_theObjectsInTile.push_back(sf::Sprite(Resources::getInstance().gettoolBarTexture()[4]));
}


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

void Tile::setSprite(sf::Sprite& sprite)
{
    m_theObjectsInTile[0] = sprite;
    m_theObjectsInTile[0].setPosition(getSprite().getPosition());

}

void Tile::setIsEraseble(bool isEraseble)
{
    m_isEraseble = isEraseble;
}
void Tile::setSymbol(char symbol)
{
    m_symbol = symbol;
}


char Tile::getSymbol()
{
    return m_symbol;
}

Tile::~Tile()
{
}