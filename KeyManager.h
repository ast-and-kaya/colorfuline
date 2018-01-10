/*
*	○キーダウンを押した時のみに制限
*	push_key関数をif文の条件式で呼び出し≪引数 sf::Keyboard::Key≫
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
	static bool m_key_lock[101];//101はキーの種類
};
