#pragma once
#include "SFML\Graphics.hpp"
#include "WindowManager.h"
#include <iostream>
#include <vector>
#include <codecvt>

using namespace std;

class CharacterDisplay
{
public:
	CharacterDisplay();
	~CharacterDisplay();

	void render(string key);

	void setFont(string key,string path);
	void setCharacter(string key, string font, string chara, sf::Vector2f pos, int size = 80, sf::Color color = sf::Color(255,255,255,255));

	sf::Vector2f getPosition(string key);

	void changeString(string key, string chara);//ï∂éöïœçX
	void changeColor(string key, sf::Color color);
	void changePosition(string key, sf::Vector2f pos);

	enum Align
	{
		Left,
		Center,
		Right,
	};
	void setOrigin(string key, Align align);

	void setOrigin(string key, sf::Vector2f vec);

	sf::Vector2f getBox(string key);

private:
	wstring_convert<codecvt_utf8<wchar_t>, wchar_t> cv;
	WindowManager windowManager;

	map<string, sf::Font> m_font;
	map<string, sf::Text> m_text;
};

