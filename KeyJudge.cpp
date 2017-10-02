#include "KeyJudge.h"

sf::Color KeyJudge::m_key_color;

KeyJudge::KeyJudge()
{
}


KeyJudge::~KeyJudge()
{
}

void KeyJudge::initialize()
{
	m_cnt[0] = 0;
	m_cnt[1] = 0;
	m_cnt[2] = 0;
}

void KeyJudge::update()
{
	if (keyManager.push_key(sf::Keyboard::J) && m_cnt[0] == 0) m_cnt[0] = 6;
	if (keyManager.push_key(sf::Keyboard::K) && m_cnt[1] == 0) m_cnt[1] = 6;
	if (keyManager.push_key(sf::Keyboard::L) && m_cnt[2] == 0) m_cnt[2] = 6;

	for (int i = 0; i < 3; i++)
	{
		m_cnt[i] -= (m_cnt[i] != 0) ? 1 : 0;
	}

	m_key_color = sf::Color(0, 0, 0, 255);

	if (m_cnt[0] != 0) m_key_color.r = 255;
	if (m_cnt[1] != 0) m_key_color.g = 255;
	if (m_cnt[2] != 0) m_key_color.b = 255;

	//if ((bool)m_key_color.r || (bool)m_key_color.g || (bool)m_key_color.b)
	//{
	//	cout << (bool)m_key_color.r
	//		 << (bool)m_key_color.g
	//		 << (bool)m_key_color.b
	//		 << endl;
	//}
}

sf::Color KeyJudge::getKeyColor()
{
	return m_key_color;
}
