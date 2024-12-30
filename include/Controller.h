#pragma once
#include "Window.h"
#include "Board.h"
#include "Menu.h"

class Controller
{
public:
	Controller();
	~Controller();

private:
	void runEdit();

	Board m_board;
	Menu m_menu;
	Window m_window;
};