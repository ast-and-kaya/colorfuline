/*
*	○カーソルが動いたときのみ位置を取得
*	（常に位置を取得する場合はsf::Mouse::getPosition()）
*	getMousePos()はウィンドウの左上が(0,0)
*	getMousePos2()はウィンドウの中心が(0,0)
*	
*/

#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#include "WindowManager.h"

using namespace std;

class MouseManager
{
public:
	MouseManager() {
	};
	~MouseManager() {
	};

	sf::Vector2f getMousePos() {
		x = sf::Mouse::getPosition(*windowManager.getWindow()).x;
		y = sf::Mouse::getPosition(*windowManager.getWindow()).y;

		return sf::Vector2f(x, y);
	};
	sf::Vector2f getMousePos2() {
		x = sf::Mouse::getPosition(*windowManager.getWindow()).x - windowManager.getWindow()->getSize().x / 2;
		y = sf::Mouse::getPosition(*windowManager.getWindow()).y - windowManager.getWindow()->getSize().y / 2;

		return sf::Vector2f(x, y);
	};
	bool push_button(sf::Mouse::Button button) {
		bool b = false;
		if (sf::Mouse::isButtonPressed(button) && !m_button_lock[button])
		{
			m_button_lock[button] = true;
			b = true;
		}
		if (!sf::Mouse::isButtonPressed(button)) m_button_lock[button] = false;

		return b;
	};

	int x, y;

private:
	WindowManager windowManager;

	bool m_button_lock[6];
};