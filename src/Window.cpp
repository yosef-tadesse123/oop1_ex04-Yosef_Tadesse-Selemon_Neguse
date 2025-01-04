#include "Window.h"


Window::Window()
{
}

// Opens a new window with the specified number of columns and rows.
//----------------------------------------------------------------
void Window::open(unsigned cols, unsigned rows) {
	m_window.create(sf::VideoMode(cols * 50, rows * 50), "Bomberman");
}

// Checks if the window is open.
//----------------------------------------------------------------
bool Window::isOpen() {
	return m_window.isOpen();
}

// Handles window events such as closing the window.
//----------------------------------------------------------------
void Window::eventFunc() {
	if (auto event = sf::Event{}; m_window.pollEvent(event)) {
		switch (event.type) {
		case sf::Event::Closed:
			close();
			exit(EXIT_SUCCESS);
			break;
		case sf::Event::MouseButtonReleased:
			checkMouseReleased(event);
			return;
		}
	}
	m_mousePressed.x = -1;
	m_mousePressed.y = -1;
}

//------------------------------------------------------------------//
// checkMouseReleased
void Window::checkMouseReleased(sf::Event event) {

	switch (event.mouseButton.button)
	{
	case sf::Mouse::Button::Left:
		m_mousePressed = sf::Vector2f(m_window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y }));
		return;
	}
	m_mousePressed.x = -1;
	m_mousePressed.y = -1;
}

// Returns the reference to the window object.
//----------------------------------------------------------------
sf::RenderWindow& Window::getWindow() {
	return  m_window;
}

//return mouse position 
//----------------------------------------------------------------
sf::Vector2f Window::getMousePressed() {
	return m_mousePressed;
}

// Closes the window.
//----------------------------------------------------------------
void Window::close() {
	m_window.close();
}

// Clears the window.
void Window::clear() {
	m_window.clear();
}

// Displays the contents of the window.
//----------------------------------------------------------------
void Window::display() {
	m_window.display();
}


Window::~Window()
{
}

