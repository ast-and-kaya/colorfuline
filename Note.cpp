#include "Note.h"



Note::Note()
{
}


Note::~Note()
{
}

void Note::update() {
}

void Note::render() {
	windowManager.getWindow()->draw(m_sprite);
}

int Note::judge(float sec, sf::Color color) {
	
	return 0;
}

void Note::setNote(float sec, sf::Color color) {
	m_sec = sec;
	m_color = color;

	m_sprite.setTexture(tex.get("game_note"));
}

float Note::getSec() {
	return m_sec;
}