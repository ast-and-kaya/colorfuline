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

	//ÉÅÉCÉì
	m_sprite.setTexture(tex.get("game_judge_line"));
	m_sprite.setPosition(0, config.getLaneDistance());
	m_sprite.setOrigin(0, tex.get("game_judge_line").getSize().y / 2.f);
	//ï`âÊ
	m_shad.loadFromFile("data/shader/judge_line.frag",sf::Shader::Fragment);
	m_shad.setParameter("r", sf::Vector2f(config.m_window_size.x, config.m_window_size.y));
	m_shad.setParameter("a", m_margin_f);
	m_shad.setParameter("b", m_margin_s);
	m_state.shader = &m_shad;


	//ÉTÉu
	m_sprite_sub.setTexture(tex.get("game_judge_line_sub"));
	m_sprite_sub.setPosition(0, config.getLaneDistance());
	m_sprite_sub.setOrigin(0, tex.get("game_judge_line_sub").getSize().y / 2.f);
	for (int i = 0; i < 3; i++) m_sub_color[i] = 0;
	m_sprite_sub.setColor(sf::Color(m_sub_color[0], m_sub_color[1], m_sub_color[2], 255));
}

void JudgeLine::update()
{
	//åıÇÈÇ∆Ç±ÇÎ
	m_sub_color[0] = (keyJudge.getKeyColor().r != 0) ? 255 : m_sub_color[0];
	m_sub_color[1] = (keyJudge.getKeyColor().g != 0) ? 255 : m_sub_color[1];
	m_sub_color[2] = (keyJudge.getKeyColor().b != 0) ? 255 : m_sub_color[2];
	
	for (int i = 0; i < 3; i++)
	{
		m_sub_color[i] -= (m_sub_color[i] > 0) ? 10 : 0;
		m_sub_color[i] = (m_sub_color[i] < 0) ? 0 : m_sub_color[i];
	}
	
	int alpha = 0;
	for (int i = 0; i < 3; i++)
	{
		alpha = (alpha < m_sub_color[i]) ? m_sub_color[i] : alpha;
	}
	if (m_pre) m_sprite_sub.setColor(sf::Color(m_sub_color[0], m_sub_color[1], m_sub_color[2], alpha));

	//ç≈èâÇÃêLÇ—ÇÈÇ∆Ç±ÇÎ
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
	windowManager.getWindow()->draw(m_sprite_sub);
	windowManager.getWindow()->draw(m_sprite, m_state);
}

bool JudgeLine::pre()
{
	return m_pre;
}
