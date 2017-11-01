#pragma once
#include "WindowManager.h"
#include <iostream>
#include "TextureManager.h"
#include "SFML\Graphics.hpp"

#include <chrono>


using namespace std;

class DecEffect
{
public:
	DecEffect();
	~DecEffect();

	void initialize();
	void update();
	void render();

	void setJudge(int j);//à¯êî1~3

private:
	WindowManager windowManager;
	TextureManager tex;

	sf::Vector2f randPos();

	struct Ring
	{
		sf::Sprite s_sprite;
		float s_scale;//0~1
		int s_alpha;//0~255
	};

	vector<Ring> m_ring;
};

