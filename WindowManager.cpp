#include "WindowManager.h"

sf::RenderWindow* WindowManager::m_window;
bool WindowManager::m_window_active;

WindowManager::WindowManager()
{
}


WindowManager::~WindowManager()
{
}

void WindowManager::setWindow(sf::RenderWindow* window)
{
	m_window = window;
}

sf::RenderWindow* WindowManager::getWindow()
{
	return m_window;
}

void WindowManager::setWindowActive(bool a) {
	m_window_active = a;
}

bool WindowManager::getWindowActive() {
	return m_window_active;
}