#include "KeyManager.h"

bool KeyManager::m_key_lock[101];

bool KeyManager::push_key(sf::Keyboard::Key key) {
	bool b = false;
	if (sf::Keyboard::isKeyPressed(key) && !m_key_lock[key])
	{
		m_key_lock[key] = true;
		b = true;
	}
	if (!sf::Keyboard::isKeyPressed(key)) m_key_lock[key] = false;

	if (windowManager.getWindowActive()) return b;
	else return 0;
}