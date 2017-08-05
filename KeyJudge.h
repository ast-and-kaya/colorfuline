#pragma once
#include "KeyManager.h"
#include <SFML\Graphics.hpp>

class KeyJudge
{
public:
	KeyJudge();
	~KeyJudge();

	void update();

	sf::Color getKeyColor();

private:
	KeyManager keyManager;

	static sf::Color m_key_color;

};

