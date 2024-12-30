#pragma once
#include "Objects.h"
#include "Resources.h"
#include "Button.h"

class Menu : public Objects
{
public:
	Menu(sf::Texture& textur = Resources::getInstance().getGeneralTexture()[2]);
	void initilaize(float cols, float rows);
	void draw(sf::RenderWindow& window);

	~Menu();

private:
	std::vector<Button> m_buttons;

};
