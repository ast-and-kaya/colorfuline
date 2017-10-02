#include "TimeCourse.h"



TimeCourse::TimeCourse()
{
}


TimeCourse::~TimeCourse()
{
}

void TimeCourse::initialize()
{
	m_sprite.setTexture(tex.get("game_course_ring"));
	m_sprite.setPosition(1920 - 300, 20);

	m_shad.loadFromFile("data/shader/time_course.frag", sf::Shader::Fragment);
	m_shad.setParameter("tex_r", tex.get("game_course_ring"));
	m_shad.setParameter("tex_f", tex.get("game_course_fade"));
	m_state.shader = &m_shad;
}

void TimeCourse::update(float now, float duration)
{
	int rgb[3] = {
		(0.5+sin(m_clock.getElapsedTime().asSeconds())) * 255,
		(0.5+sin(m_clock.getElapsedTime().asSeconds() + M_PI/3.f*2.f)) * 255,
		(0.5+sin(m_clock.getElapsedTime().asSeconds() + M_PI/3.f*4.f)) * 255
	};

	for (int i = 0; i < 3; i++) {
		rgb[i] = (rgb[i] > 255) ? 255 : rgb[i];
		rgb[i] = (rgb[i] < 0) ? 0 : rgb[i];
	}

	m_sprite.setColor(sf::Color(rgb[0],rgb[1],rgb[2],255));
	
	//------------
	
	float t = now / duration;

	m_shad.setParameter("t", t);
}

void TimeCourse::render()
{
	windowManager.getWindow()->draw(m_sprite, m_state);
}
