/*
*	���L�[�_�E�������������݂̂ɐ���
*	push_key�֐���if���̏������ŌĂяo������� sf::Keyboard::Key��
*/

#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "WindowManager.h"

using namespace std;

class KeyManager
{
public:
	KeyManager() {
	};
	~KeyManager() {
	};

	bool push_key(sf::Keyboard::Key key);

private:
	WindowManager windowManager;
	static bool m_key_lock[101];//101�̓L�[�̎��
};
