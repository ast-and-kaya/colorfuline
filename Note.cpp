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

	float frame = 1.f / 60.f;
	m_j_perfect = frame * 2;
	m_j_great = frame * 8;
	m_j_good = frame * 16;
}

void Note::update(float music_offset) {
	sf::Vector2f pos(0, lerp(music_offset));
	m_sprite.setPosition(pos);

}

void Note::render() {
	windowManager.getWindow()->draw(m_sprite);
}

int Note::judge(float sec, sf::Color color) { // 0:miss 1:perfect 2:great 3:good 

	//cout << color.r << endl;

	if (m_color != color)
	{
		return 0;
	}

	if (abs(m_sec - sec) <= m_j_perfect / 2.f) return 1;
	if (abs(m_sec - sec) <= m_j_great / 2.f) return 2;
	if (abs(m_sec - sec) <= m_j_good / 2.f) return 3;
	
	return 0;
}

bool Note::rangeOut(float sec)
{
	return (sec > m_sec + m_j_good) ? true : false;
}

float Note::getSec() {
	return m_sec;
}

float Note::lerp(float music_offset)
{
	float f = 900 + (-1)*((m_sec - music_offset) * 900 * 1.0);
	return f;
}
