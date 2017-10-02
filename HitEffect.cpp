#include "HitEffect.h"



HitEffect::HitEffect()
{
}


HitEffect::~HitEffect()
{
}

void HitEffect::initialize()
{
	m_va.setPrimitiveType(sf::Quads);
	for (int i = 0; i < 1920/20; i++)
	{
		m_va_size.push_back(sf::Vector2i(10,0));
	}

	m_color = sf::Color::Transparent;
}

void HitEffect::update()
{
	m_va.clear();
	sf::Vector2f position(0, config.getLaneDistance());
	//color = sf::Color(255,0,130,255);
	for (int i = 0; i < m_va_size.size(); i++)
	{
		m_color.a = 80;
		m_va.append(sf::Vertex(position + sf::Vector2f( i * 20, 0), m_color));
		m_va.append(sf::Vertex(position + sf::Vector2f( i * 20 + m_va_size[i].x, 0), m_color));
		m_color.a = 0;
		m_va.append(sf::Vertex(position + sf::Vector2f( i * 20 + m_va_size[i].x, -1 * m_va_size[i].y), m_color));
		m_va.append(sf::Vertex(position + sf::Vector2f( i * 20, -1 * m_va_size[i].y), sf::Color::Transparent));
		
		m_va_size[i].y -= 75;
		m_va_size[i].y = (m_va_size[i].y < 0) ? 0 : m_va_size[i].y;
	}

}

void HitEffect::render()
{
	windowManager.getWindow()->draw(m_va);
}

void HitEffect::action()
{
	m_color = keyJudge.getKeyColor();

	for (int i = 0; i < m_va_size.size(); i++)
	{
		//int x = abs((int)(m_va_size.size() / 2) - i);
		int x = m_va_size.size() / 2 - abs((int)(m_va_size.size() / 2) - i);
		m_va_size[i].y = x*(x*0.5) + 200 + rand() % 300;
		//cout << m_va_size[i].y << endl;
	}
}
