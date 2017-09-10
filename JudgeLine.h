#pragma once
#include "WindowManager.h"
#include "TextureManager.h"
#include "ConfigManager.h"
#include "KeyManager.h"
#include <SFML\Graphics.hpp>

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

	bool pre();//0:€”õ 1:Š®—¹

private:
	WindowManager windowManager;
	KeyManager keyManager;
	TextureManager tex;
	ConfigManager config;

	sf::Sprite m_sprite;

	float margin;//0~1
	sf::RenderStates m_state;
	sf::Shader m_shad;
	float m_margin_f; // ‰æ–ÊƒTƒCƒY¨1.0f
	float m_margin_s; // 1.0f ¨ 0.0f

	bool m_pre;
};

