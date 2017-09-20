#include "SupportLine.h"



SupportLine::SupportLine()
{
}


SupportLine::~SupportLine()
{
}

void SupportLine::initialize()
{
	m_color = sf::Vector3f(0, 0, 0);

	m_sprite.setTexture(tex.get("black"));

	m_shad.loadFromFile("data/shader/support_line.frag", sf::Shader::Fragment);
	m_shad.setParameter("r", sf::Vector2f(windowManager.getWindow()->getSize().x, windowManager.getWindow()->getSize().y));
	m_state.shader = &m_shad;

	//tex_test.loadFromFile("data/image/test_bg.png");
	test.setTexture(tex_test);
}

void SupportLine::update()
{
}

void SupportLine::render()
{
	//windowManager.getWindow()->draw(test);
	windowManager.getWindow()->draw(m_sprite,m_state);
}

void SupportLine::setColor(sf::Vector3f color)
{
}
