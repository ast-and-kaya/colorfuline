#pragma once
#include "SFML\Graphics.hpp"
#include <iostream>

#include "WindowManager.h"
#include "ConfigManager.h"

#include "KeyJudge.h"
#include <math.h>

using namespace std;

class HitEffect
{
public:
	HitEffect();
	~HitEffect();

	void initialize();
	void update();
	void render();

	void action();

private:
	WindowManager windowManager;
	ConfigManager config;
	KeyJudge keyJudge;

	sf::VertexArray m_va;

	vector<sf::Vector2i> m_va_size;

	sf::Color m_color;
};

