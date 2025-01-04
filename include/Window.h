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
	sf::Vector2f getMousePressed();

	~Window();

private:
	void checkMouseReleased(sf::Event event);

	sf::RenderWindow m_window;
	sf::Vector2f m_mousePressed;
};