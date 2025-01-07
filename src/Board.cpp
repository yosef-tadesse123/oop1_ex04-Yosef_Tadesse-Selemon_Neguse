#pragma once
#include "Board.h"
#include "Resources.h"
#include <iostream>
#include <fstream>

//-------------------------------------- Board ---------------------------------------------
// Constructor: Initializes the board with a default background texture.
Board::Board()
    :m_background(Resources::getInstance().getGeneralTexture()[0])
{
}

//--------------------------------------- initialize ------------------------------------------------
// Initializes the board with columns, rows, tiles, and scaling.
void Board::initilaize(float cols, float rows)
{
    m_cols = cols;
    m_rows = rows;
    initilaizeTiles();
    scale();
}
//--------------------------------------- initializeTiles ------------------------------------------------
// Creates and positions the tiles based on board dimensions.
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
//--------------------------------------- respond ------------------------------------------------
// Handles user interactions such as saving, clearing, or updating tiles.
void Board::respond(sf::Vector2f mousePressed, sf::RenderWindow& window, char& symbol)
{
    if (symbol == 'S')
    {
        saveBoard();
        return;
    }
    else if (symbol == 'T')
    {
        m_tiles.clear();
        window.close();
        return;
    }

    for (size_t i = 0; i < m_tiles.size(); i++)
    {

        if (symbol == 'E')
        {
            if (m_tiles[i].getSymbol() != ' ')
            {
                m_tiles[i].setIsEraseble(true);
            }
        }
        else
        {
            m_tiles[i].setIsEraseble(false);
        }

        if (m_tiles[i].getSprite().getGlobalBounds().contains(mousePressed))
        {
            updateTile(symbol, i);
            break;
        }
    }
}
//--------------------------------------- updateTile ------------------------------------------------
// Updates the tile's sprite and symbol based on user input.
void Board::updateTile(char symbol, int i) {
    sf::Sprite sprite;
    switch (symbol) {
    case 'D':
        sprite.setTexture(Resources::getInstance().getGameObjectTexture()[0]);
        break;
    case '#':
        sprite.setTexture(Resources::getInstance().getGameObjectTexture()[1]);
        break;
    case '@':
        sprite.setTexture(Resources::getInstance().getGameObjectTexture()[2]);
        break;
    case '/':
        removeRobot();
        sprite.setTexture(Resources::getInstance().getGameObjectTexture()[3]);
        break;
    case '!':
        sprite.setTexture(Resources::getInstance().getGameObjectTexture()[4]);
        break;
    case 'E':
        sprite.setTexture(sf::Texture()); // Clear texture
        m_tiles[i].setSymbol(' '); // Set symbol to space
        m_tiles[i].setIsEraseble(false); // Mark as not erasable
        m_tiles[i].setSprite(sprite); // Update sprite
        break;
    default:
        break;
    }

    // Update tile attributes
    if (symbol != 'E')
        m_tiles[i].setSymbol(symbol);

    m_tiles[i].setSprite(sprite);
}

//--------------------------------------- removeRobot ------------------------------------------------
// Removes the first robot found on the board
void Board::removeRobot() {
    sf::Sprite sprite;
    sprite.setTexture(sf::Texture());
    for (int i = 0; i < m_tiles.size(); i++)
    {
        if (m_tiles[i].getSymbol() == '/')
        {
            m_tiles[i].setSymbol(' ');
            m_tiles[i].setSprite(sprite);
            return;
        }
    }
}

//--------------------------------------- saveBoard ------------------------------------------------
// Saves the board's state to a text file.
void Board::saveBoard() {
    // Open file in write mode, which truncates the file if it already exists
    std::ofstream file("Board.txt", std::ios::out);

    if (!file) {
        std::cerr << "Cannot open file" << std::endl;
        exit(EXIT_FAILURE); // Exit if the file cannot be opened
    }

    // Write board data
    for (int i = 0; i < m_rows; i++) {
        for (int j = 0; j < m_cols; j++) {
            file << m_tiles[j+(m_cols*i)].getSymbol();
        }
        file << '\n';
    }

    file.close();
}
//--------------------------------------- draw ------------------------------------------------
// Draws the board's background and all tiles on the window.
void Board::draw(sf::RenderWindow& window) {
    window.draw(m_background);

    for (size_t i = 0; i < m_tiles.size(); i++)
    {
        m_tiles[i].draw(window);
    }


}

//--------------------------------------- scale ------------------------------------------------
// Scales the board's background based on its dimensions.
void Board::scale()
{
    m_background.setScale(1.0f, 1.0f);
    m_background.scale(m_cols / 10.f, m_rows / 10.f);
}
//--------------------------------------- Destructor ------------------------------------------------
// Destructor: Cleans up the board's resources.
Board::~Board()
{
}
