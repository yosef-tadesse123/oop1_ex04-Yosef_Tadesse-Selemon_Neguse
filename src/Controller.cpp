
#include <iostream>
#include "Controller.h"

Controller::Controller()
{
	float rows, cols;

	while (true)
	{
		std::cout << "please enter num of cols and rows\n";
		std::cin >> cols >> rows;

		m_board.initilaize(cols, rows);
		m_menu.initilaize(cols, rows);

		m_window.open(unsigned(cols), unsigned(rows));

		runEdit();

	}

}

void Controller::runEdit()
{
	while (m_window.isOpen())
	{
		m_window.clear();

		m_board.draw(m_window.getWindow());
		m_menu.draw(m_window.getWindow());

		m_window.display();
		m_window.eventFunc();
	}
}

Controller::~Controller()
{
}