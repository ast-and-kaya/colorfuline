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
}

int Note::judge(float sec, sf::Color color) {
	
	return 0;
}

void Note::setNote(float sec, sf::Color color) {
	m_sec = sec;
	m_color = color;
}

bool Note::getSec() {
	return m_sec;
}