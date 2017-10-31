#pragma once
#include "KeyManager.h"
#include <SFML\Graphics.hpp>

class KeyJudge
{
public:
	KeyJudge();
	~KeyJudge();

	void initialize();
	void update();

	sf::Color getKeyColor();

	void resetKey();

private:
	KeyManager keyManager;

	static sf::Color m_key_color;

	int m_cnt[3];//rgb
};

