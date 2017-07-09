#pragma once
#include "WindowManager.h"
#include "TextureManager.h"
#include "SFML\Graphics.hpp"
#include <iostream>

using namespace std;

class Note
{
public:
	Note();
	~Note();

	void setNote(float sec, sf::Color color);
	void update(float music_offset);
	void render();

	int judge(float sec, sf::Color color);
	float getSec();

private:
	WindowManager windowManager;
	TextureManager tex;

	float lerp(float music_offset);

	sf::Sprite m_sprite;

	float m_sec;
	sf::Color m_color;

};