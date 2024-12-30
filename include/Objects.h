#pragma once
#include <SFML/Graphics.hpp>

class Objects
{
public:
	Objects();
	Objects(sf::Texture& texture);

	void scale(float cols, float rows);
	void setPosition(sf::Vector2f pos);
	void draw(sf::RenderWindow& window);
	sf::Sprite& getSprite();

	~Objects();

private:
	sf::Sprite m_sprite;

};