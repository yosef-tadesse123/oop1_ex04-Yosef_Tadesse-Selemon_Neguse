#pragma once
#include "Objects.h"

class Button : public Objects
{
public:
	Button(sf::Texture& texture, char symbol);
	char getSymbol();


	~Button();
private:
	char m_symbol;
};