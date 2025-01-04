#include "Button.h"



Button::Button(sf::Texture& texture, char symbol)
	:Objects(texture), m_symbol(symbol)
{
}

char Button::getSymbol()
{
	return m_symbol;
}

Button::~Button()
{
}