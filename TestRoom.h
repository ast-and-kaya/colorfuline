#pragma once
#include <SFML/Audio.hpp>
#include "Scene.h"
#include <iostream>

#include "TextureManager.h"

using namespace std;

class TestRoom :
	public Scene
{
public:
	TestRoom();
	~TestRoom();

	void initialize();
	Scene* update();
	void render();

private:
	WindowManager windowManager;
	KeyManager keyManager;
	MouseManager mouseManager;
	TextureManager tex;

	sf::Sprite m_bg;
	sf::Texture m_tex;

	sf::RenderStates m_state;
	sf::Shader m_shad;
};