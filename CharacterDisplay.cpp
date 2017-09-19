#include "CharacterDisplay.h"



CharacterDisplay::CharacterDisplay()
{
}


CharacterDisplay::~CharacterDisplay()
{
}

void CharacterDisplay::setFont(string key, string path)
{
	m_font.insert(map<string, sf::Font>::value_type(key, sf::Font()));
	m_font[key].loadFromFile(path);
}

void CharacterDisplay::render(string key)
{
	windowManager.getWindow()->draw(m_text[key]);
}

void CharacterDisplay::setCharacter(string key, string font, string chara, sf::Vector2f pos, int size, sf::Color color)
{
	m_text.insert(map<string, sf::Text>::value_type(key, sf::Text()));
	m_text[key].setFont(m_font[font]);
	m_text[key].setString(cv.from_bytes(chara));
	m_text[key].setPosition(pos);
	m_text[key].setCharacterSize(size);
	m_text[key].setColor(color);
}

sf::Vector2f CharacterDisplay::getPosition(string key)
{
	return m_text[key].getPosition();
}

void CharacterDisplay::changeString(string key, string chara)
{
	m_text[key].setString(cv.from_bytes(chara));
}

void CharacterDisplay::changeColor(string key, sf::Color color)
{
	m_text[key].setColor(color);
}

void CharacterDisplay::changePosition(string key, sf::Vector2f pos)
{
	m_text[key].setPosition(pos);
}

void CharacterDisplay::setOrigin(string key, Align align)
{
	if ((int)align == 0)//left
	{
		m_text[key].setOrigin(0, 0);
	}
	if ((int)align == 1)//center
	{
		m_text[key].setOrigin(m_text[key].getGlobalBounds().width / 2.f, 0);
	}
	if ((int)align == 2)//right
	{
		m_text[key].setOrigin(m_text[key].getGlobalBounds().width, 0);
	}
}

void CharacterDisplay::setOrigin(string key, sf::Vector2f vec)
{
	m_text[key].setOrigin(vec);
}

sf::Vector2f CharacterDisplay::getBox(string key)
{
	return sf::Vector2f( m_text[key].getGlobalBounds().width, m_text[key].getGlobalBounds().height);
}

