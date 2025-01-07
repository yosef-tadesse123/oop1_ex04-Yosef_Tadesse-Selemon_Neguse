#include "Button.h"



//--------------------------------------- Constructor ------------------------------------------------
// Initializes the button with a texture and a symbol.
Button::Button(sf::Texture& texture, char symbol)
	:Objects(texture), m_symbol(symbol)
{
}
//--------------------------------------- getSymbol ------------------------------------------------
// Returns the symbol associated with the button.
char Button::getSymbol()
{
	return m_symbol;
}
//--------------------------------------- Destructor ------------------------------------------------
// Cleans up the button's resources.
Button::~Button()
{
}