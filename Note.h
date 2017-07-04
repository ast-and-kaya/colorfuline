#pragma once
#include "WindowManager.h"
#include "TextureManager.h"
#include "SFML\Graphics.hpp"
#include "GameScene.h"
#include <iostream>

using namespace std;

class Note
{
public:
	Note();
	~Note();

	void setNote(float sec, sf::Color color);

	int judge(float sec, sf::Color color);

	bool getSec();

	void update();
	void render();

private:
	WindowManager windowManager;
	TextureManager tex;

	sf::Sprite m_sprite;

	float m_sec;
	sf::Color m_color;

};