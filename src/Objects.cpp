#include "Objects.h"


Objects::Objects(sf::Texture & texture)
	:m_sprite(texture)
{
}

Objects::Objects()
{

}

void Objects::scale(float cols, float rows)
{
	m_sprite.scale(cols, rows);
}

void Objects::setPosition(sf::Vector2f pos)
{
	m_sprite.setPosition(pos);
}

void Objects::draw(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}

sf::Sprite& Objects::getSprite()
{
	return m_sprite;
}


Objects::~Objects()
{
}