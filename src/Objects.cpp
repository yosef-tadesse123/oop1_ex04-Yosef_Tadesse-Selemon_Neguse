#include "Objects.h"

//--------------------------------------- Constructor ------------------------------------------------
// Initializes the object with a given texture.
Objects::Objects(sf::Texture & texture)
	:m_sprite(texture)
{
}
//--------------------------------------- Default Constructor ------------------------------------------------
// Default constructor for the object without initializing a texture.
Objects::Objects()
{

}
//--------------------------------------- scale ------------------------------------------------
// Scales the object's sprite based on the given width and height ratios.
void Objects::scale(float cols, float rows)
{
	m_sprite.scale(cols, rows);
}

//--------------------------------------- setPosition ------------------------------------------------
// Sets the position of the object's sprite.
void Objects::setPosition(sf::Vector2f pos)
{
	m_sprite.setPosition(pos);
}

//--------------------------------------- draw ------------------------------------------------
// Draws the object's sprite to the given render window.
void Objects::draw(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}
//--------------------------------------- getSprite ------------------------------------------------
// Returns a reference to the object's sprite.
sf::Sprite& Objects::getSprite()
{
	return m_sprite;
}

//--------------------------------------- Destructor ------------------------------------------------
// Cleans up the object's resources.
Objects::~Objects()
{
}