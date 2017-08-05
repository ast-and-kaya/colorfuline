#include "KeyJudge.h"

sf::Color KeyJudge::m_key_color;

KeyJudge::KeyJudge()
{
}


KeyJudge::~KeyJudge()
{
}

void KeyJudge::update()
{
	m_key_color = sf::Color(0, 0, 0, 255);

	if (keyManager.push_key(sf::Keyboard::J)) m_key_color.r = 255;
	if (keyManager.push_key(sf::Keyboard::K)) m_key_color.g = 255;
	if (keyManager.push_key(sf::Keyboard::L)) m_key_color.b = 255;

}

sf::Color KeyJudge::getKeyColor()
{
	return m_key_color;
}
