#pragma once

#include <SFML/Graphics.hpp>
class WindowManager
{
public:
	WindowManager();
	~WindowManager();

	static sf::RenderWindow* m_window;

	void setWindow(sf::RenderWindow* window);
	sf::RenderWindow* getWindow();

	void setWindowActive(bool a);
	bool getWindowActive();

private:
	static bool m_window_active;
};