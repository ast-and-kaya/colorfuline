#pragma once
#include "SFML\Graphics.hpp"
#include "WindowManager.h"
#include <iostream>
#include <vector>

using namespace std;

class CharacterDisplay
{
public:
	CharacterDisplay();
	~CharacterDisplay();

	void render();

	void setFont(string key,string path);
	void setCharacter(string key, string font, string chara, sf::Vector2f pos, int size = 200, sf::Color color = sf::Color(255,255,255,255));

	void changeString(string key, string chara);//ï∂éöïœçX

private:
	WindowManager windowManager;

	map<string, sf::Font> m_font;
	map<string, sf::Text> m_text;
};

