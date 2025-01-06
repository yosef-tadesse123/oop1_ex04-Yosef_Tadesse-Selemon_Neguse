#include "Menu.h"
#include <iostream>
#include <fstream>
#include <string>

Menu::Menu(sf::Texture& texture)
	:Objects(texture)
{
	std::ifstream file("Toolbar.txt"); // Open the file
	if (!file) {
		std::cerr << "The file 'Toolbar.txt' was not found." << std::endl;
		exit(EXIT_FAILURE);
	}

	std::string line;
	std::getline(file, line);

	for (size_t i = 0; i < line.size(); i++)
	{
		switch (line[i])
		{
		case 'D'://door
			m_buttons.push_back(Button(Resources::getInstance().getGameObjectTexture()[0],'D'));
			break;
		case '#'://wall
			m_buttons.push_back(Button(Resources::getInstance().getGameObjectTexture()[1],'#'));
			break;
		case '@'://rock
			m_buttons.push_back(Button(Resources::getInstance().getGameObjectTexture()[2],'@'));
			break;
		case '/'://robot
			m_buttons.push_back(Button(Resources::getInstance().getGameObjectTexture()[3],'/'));
			break;
		case '!'://enemy
			m_buttons.push_back(Button(Resources::getInstance().getGameObjectTexture()[4],'!'));
			break;
		default:
			break;
		}
	}

	m_buttons.push_back(Button(Resources::getInstance().gettoolBarTexture()[0],'E'));
	m_buttons.push_back(Button(Resources::getInstance().gettoolBarTexture()[1],'T'));
	m_buttons.push_back(Button(Resources::getInstance().gettoolBarTexture()[2],'S'));
}

void Menu::initilaize(float cols, float rows)
{
	setPosition({ cols, 2.5f * rows });
	scale( cols / 21.5f, rows / 200 );
	scale(1.0f, 1.0f);

	for (size_t i = 0; i < m_buttons.size(); i++)
	{
		m_buttons[i].scale(cols / 15, rows / 15);
		//m_buttons[i].scale(1.0f, 1.0f);
		m_buttons[i].setPosition({ cols+ (i+1)*cols*5, 3.f*rows});
	}

}

void Menu::respond(sf::Vector2f mousePressed, char& symbol)
{
	
	for (size_t i = 0; i < m_buttons.size(); i++)
	{
		if (m_buttons[i].getSprite().getGlobalBounds().contains(mousePressed))
		{
			symbol = m_buttons[i].getSymbol();
			return;
		}
	}
}

void Menu::draw(sf::RenderWindow& window)
{
	Objects::draw(window);

	for (size_t i = 0; i < m_buttons.size(); i++)
	{
		m_buttons[i].draw(window);
	}
}

Menu::~Menu()
{
}