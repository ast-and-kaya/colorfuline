#include "KeyManager.h"

bool KeyManager::m_key_lock[101];

bool KeyManager::push_key(sf::Keyboard::Key key) {

	bool b = false;
	
	//�v�b�V������1�t���[���̂�true�֕ύX
	if (sf::Keyboard::isKeyPressed(key) && !m_key_lock[key])
	{
		m_key_lock[key] = true;
		b = true;
	}
	if (!sf::Keyboard::isKeyPressed(key)) m_key_lock[key] = false;

	//�E�B���h�E����A�N�e�B�u�̎���false��Ԃ�
	if (windowManager.getWindowActive()) return b;
	else return 0;
}