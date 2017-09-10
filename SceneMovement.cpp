#include "SceneMovement.h"

bool SceneMovement::m_in_out;

SceneMovement::SceneMovement()
{
}


SceneMovement::~SceneMovement()
{
}

void SceneMovement::initialize(int alpha)
{
	m_alpha = alpha;

	m_sprite.setTexture(tex.get("black"));
	m_sprite.setColor(sf::Color(0, 0, 0, m_alpha));

	m_in_out = false;
}

void SceneMovement::update()
{
	if (!m_in_out && m_alpha > 0)
	{
		m_alpha -= config.getBlackTime();
	}
	if (m_in_out && m_alpha < 255)
	{
		m_alpha += config.getBlackTime();
	}
	m_sprite.setColor(sf::Color(0, 0, 0, m_alpha));

}

void SceneMovement::render()
{
	windowManager.getWindow()->draw(m_sprite);
}

void SceneMovement::In()
{
	m_in_out = true;
}

void SceneMovement::Out()
{
	m_in_out = false;
}

int SceneMovement::getAlpha()
{
	return m_alpha;
}
