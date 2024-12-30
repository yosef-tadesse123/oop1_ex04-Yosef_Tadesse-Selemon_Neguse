#pragma once
#include <SFML/Graphics.hpp>


class Window
{
public:
	Window();
	void open(unsigned cols, unsigned rows);
	bool isOpen();
	void eventFunc();
	void clear();
	void close();
	void display();
	sf::RenderWindow& getWindow();
	~Window();

private:
	sf::RenderWindow m_window;
};