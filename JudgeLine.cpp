#include "JudgeLine.h"



JudgeLine::JudgeLine()
{
}


JudgeLine::~JudgeLine()
{
}

void JudgeLine::initialize()
{
	m_margin_f = config.m_window_size.x;
	m_margin_s = 0.0f;

	//ƒƒCƒ“
	m_sprite.setTexture(tex.get("game_judge_line"));
	m_sprite.setPosition(0, config.getLaneDistance());
	m_sprite.setOrigin(0, tex.get("game_judge_line").getSize().y / 2.f);
	//•`‰æ
	m_shad.loadFromFile("data/shader/judge_line.frag",sf::Shader::Fragment);
	m_shad.setParameter("r", sf::Vector2f(config.m_window_size.x, config.m_window_size.y));
	m_shad.setParameter("a", m_margin_f);
	m_shad.setParameter("b", m_margin_s);
	m_state.shader = &m_shad;
}

void JudgeLine::update()
{

	//Å‰‚ÌL‚Ñ‚é‚Æ‚±‚ë
	if (m_margin_f > 1.0f) {
		m_margin_f -= m_margin_f / 4.0f;
	}
	else if (m_margin_f <= 1.0f) {
		m_margin_f = 1.0f;
	}

	if (m_margin_f == 1.0f && m_margin_s < 1.0f) {
		m_margin_s += 0.04f;
	}
	else if (m_margin_s >= 1.0f) {
		m_margin_s = 1.0f;
	}

	m_shad.setParameter("a", m_margin_f);
	m_shad.setParameter("b", m_margin_s);

	if (m_margin_s == 1.0f)
	{
		m_pre = true;
	}
}

void JudgeLine::render()
{
	windowManager.getWindow()->draw(m_sprite, m_state);
}

bool JudgeLine::pre()
{
	return m_pre;
}
