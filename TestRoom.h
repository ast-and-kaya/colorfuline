#pragma once
#include <SFML/Audio.hpp>
#include "Scene.h"
#include <iostream>
#include <codecvt>

#include "MusicManager.h"
#include "ConfigManager.h"
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

	sf::Sprite s;

	sf::Shader m_shad;
	sf::RenderStates m_state;
};