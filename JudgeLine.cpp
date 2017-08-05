#include "JudgeLine.h"



JudgeLine::JudgeLine()
{
}


JudgeLine::~JudgeLine()
{
}

void JudgeLine::initialize()
{
	m_sprite.setTexture(tex.get("game_judge_line"));
	m_sprite.setPosition(0, config.getLaneDistance());
	m_sprite.setOrigin(0, tex.get("game_judge_line").getSize().y / 2.f);

	m_sprite_sub.setTexture(tex.get("game_judge_line_sub"));
	m_sprite_sub.setPosition(0, config.getLaneDistance());
	m_sprite_sub.setOrigin(0, tex.get("game_judge_line_sub").getSize().y / 2.f);
	for (int i = 0; i < 3; i++) m_sub_color[i] = 0;
	m_sprite_sub.setColor(sf::Color(m_sub_color[0], m_sub_color[1], m_sub_color[2], 255));
}

void JudgeLine::update()
{
	m_sub_color[0] = (keyJudge.getKeyColor().r != 0) ? 255 : m_sub_color[0];
	m_sub_color[1] = (keyJudge.getKeyColor().g != 0) ? 255 : m_sub_color[1];
	m_sub_color[2] = (keyJudge.getKeyColor().b != 0) ? 255 : m_sub_color[2];

	for (int i = 0; i < 3; i++)
	{
		m_sub_color[i] -= (m_sub_color[i] > 0) ? 15 : 0;
	}

	if (m_pre) m_sprite_sub.setColor(sf::Color(m_sub_color[0], m_sub_color[1], m_sub_color[2], 255));


	if (keyManager.push_key(sf::Keyboard::Space))
	{
		m_pre = true;
	}
}

void JudgeLine::render()
{
	windowManager.getWindow()->draw(m_sprite_sub);
	windowManager.getWindow()->draw(m_sprite);
}

bool JudgeLine::pre()
{
	return m_pre;
}
