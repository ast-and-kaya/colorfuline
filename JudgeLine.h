#pragma once
#include "WindowManager.h"
#include "TextureManager.h"
#include "ConfigManager.h"
#include "KeyManager.h"
#include <SFML\Graphics.hpp>

#include "KeyJudge.h"

#include <iostream>

using namespace std;

class JudgeLine
{
public:
	JudgeLine();
	~JudgeLine();

	void initialize();
	void update();
	void render();

	bool pre();//0:���� 1:����

private:
	WindowManager windowManager;
	KeyManager keyManager;
	TextureManager tex;
	ConfigManager config;
	KeyJudge keyJudge;

	sf::Sprite m_sprite;
	sf::Sprite m_sprite_sub;

	int m_sub_color[3];

	bool m_pre;
};

