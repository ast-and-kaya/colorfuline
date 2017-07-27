#include "Note.h"

Note::Note()
{
}


Note::~Note()
{
}

void Note::setNote(float sec, sf::Color color) {
	m_sec = sec;
	m_color = color;

	m_sprite.setTexture(tex.get("game_note"));
	m_sprite.setColor(color);
	m_sprite.setOrigin(sf::Vector2f(tex.get("game_note").getSize()) / 2.f);
}

void Note::update(float music_offset) {
	sf::Vector2f pos(1920 / 2.f, lerp(0, config.getLaneDistance(), -1 * (m_sec - music_offset) + 1));
	m_sprite.setPosition(pos);
	float t = pos.y / config.getLaneDistance();
	m_sprite.setScale((1 - t)*0.1 + t * 1, (1 - t)*0.5 + t * 1);
}

void Note::render() {
	windowManager.getWindow()->draw(m_sprite);
}

int Note::judge(float sec, sf::Color color) { // 0:miss 1:perfect 2:great 3:good 

	//cout << color.r << endl;

	if (m_color == color)
	{
		if (abs(m_sec - sec) <= config.getJudgeFrame(0) / 2.f) return 1;//perfect
		if (abs(m_sec - sec) <= config.getJudgeFrame(1) / 2.f) return 2;//great
		if (abs(m_sec - sec) <= config.getJudgeFrame(2) / 2.f) return 3;//good
	}
	
	return 0;
}

bool Note::rangeOut(float sec)
{
	return (sec > m_sec + config.getJudgeFrame(2)) ? true : false;
}

float Note::getSec() {
	return m_sec;
}

float Note::lerp(float s, float e, float t)
{
	t *= t * (t < 0 ? -1 : 1);
	return (1 - t) * s + t * e;
}