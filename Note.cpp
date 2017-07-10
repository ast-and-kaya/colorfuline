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
}

void Note::update(float music_offset) {
	sf::Vector2f pos(0, lerp(music_offset));
	m_sprite.setPosition(pos);

}

void Note::render() {
	windowManager.getWindow()->draw(m_sprite);
}

int Note::judge(float sec, sf::Color color) {
	
	return 0;
}

float Note::getSec() {
	return m_sec;
}

float Note::lerp(float music_offset)
{
	float f = 900 + (-1)*((m_sec - music_offset) * 900 * 1.0);
	return f;
}
