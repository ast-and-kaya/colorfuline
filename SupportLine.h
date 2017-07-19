#pragma once
#include "SFML\Graphics.hpp"
#include "WindowManager.h"
#include "TextureManager.h"
#include <iostream>

using namespace std;

class SupportLine
{
public:
	SupportLine();
	~SupportLine();

	void initialize();
	void update();
	void render();

	//0Å`1
	void setColor(sf::Vector3f color);

private:
	WindowManager windowManager;
	TextureManager tex;

	sf::Vector3f m_color;

	sf::Sprite m_sprite;

	sf::Shader m_shad;
	sf::RenderStates m_state;

	sf::Sprite test;
	sf::Texture tex_test;
};

