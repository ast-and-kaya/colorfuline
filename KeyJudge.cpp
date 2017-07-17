#include "KeyJudge.h"



KeyJudge::KeyJudge()
{
}


KeyJudge::~KeyJudge()
{
}

void KeyJudge::update()
{
	m_color = sf::Color(0, 0, 0, 255);

	if (keyManager.push_key(sf::Keyboard::J)) m_color.r = 255;
	if (keyManager.push_key(sf::Keyboard::K)) m_color.g = 255;
	if (keyManager.push_key(sf::Keyboard::L)) m_color.b = 255;

}

sf::Color KeyJudge::getKeyColor()
{
	return m_color;
}
