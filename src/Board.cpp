#pragma once
#include "Board.h"
#include "Resources.h"

Board::Board()
    :m_background(Resources::getInstance().getGeneralTexture()[0])
{
}


void Board::initilaize(float cols, float rows)
{
    m_cols = cols;
    m_rows = rows;
    initilaizeTiles();
    scale();
}

void Board::initilaizeTiles()
{

    Tile tile(Resources::getInstance().getGeneralTexture()[1]);
    float div = 0.945f;
    float col_size = 45 * div;
    float row_size = 45 * div;
    float col_pos = 3.7f * m_cols;
    float row_pos = 7.2f * m_rows;

    tile.scale(div, div);
    for (float i = 0; i < m_rows; i++)
    {
        for (float j = 0; j < m_cols; j++)
        {
            tile.setPosition({ col_size * j + col_pos, row_size * i + row_pos });
            m_tiles.push_back(tile);
        }
    }

}

void Board::draw(sf::RenderWindow& window) {
    window.draw(m_background);

    for (size_t i = 0; i < m_tiles.size(); i++)
    {
        window.draw(m_tiles[i].getSprite());
    }


}

void Board::scale()
{
    m_background.scale(m_cols / 10.f, m_rows / 10.f);
}

Board::~Board()
{
}
