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

void CharacterDisplay::render()
{
	for (auto& it : m_text)
	{
		windowManager.getWindow()->draw(it.second);
	}
}

void CharacterDisplay::setCharacter(string key, string font, string chara, sf::Vector2f pos, int size, sf::Color color)
{
	m_text.insert(map<string, sf::Text>::value_type(key, sf::Text()));
	m_text[key].setFont(m_font[font]);
	m_text[key].setString(chara);
	m_text[key].setPosition(pos);
	m_text[key].setCharacterSize(size);
	m_text[key].setColor(sf::Color(255, 255, 255, 100));
}

void CharacterDisplay::changeString(string key, string chara)
{
	m_text[key].setString(chara);
}
