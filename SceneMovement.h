#pragma once
#include <SFML\Graphics.hpp>
#include "TextureManager.h"
#include "WindowManager.h"
#include "ConfigManager.h"
#include <iostream>

using namespace std;

class SceneMovement
{
public:
	SceneMovement();
	~SceneMovement();

	void initialize(int alpha = 255);

	void update();

	void render();

	void In();//ìßÅ®çï
	void Out();//çïÅ®ìß

	int getAlpha();

private:
	WindowManager windowManager;
	TextureManager tex;
	ConfigManager config;

	sf::Sprite m_sprite;

	int m_alpha; // 0~255
	bool m_in_out;
};

