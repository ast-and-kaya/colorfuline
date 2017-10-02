#pragma once
#include <iostream>

#define _USE_MATH_DEFINES
#include <math.h>

#include "SFML\Graphics.hpp"
#include "WindowManager.h"
#include "TextureManager.h"

using namespace std;

class TimeCourse
{
public:
	TimeCourse();
	~TimeCourse();

	void initialize();
	void update(float now, float duration);
	void render();

private:
	WindowManager windowManager;
	TextureManager tex;

	sf::Sprite m_sprite;

	sf::RenderStates m_state;
	sf::Shader m_shad;

	sf::Clock m_clock;
};

