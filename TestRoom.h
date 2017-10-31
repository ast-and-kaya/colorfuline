#pragma once
#include <SFML/Audio.hpp>
#include "Scene.h"
#include <iostream>

#include "TextureManager.h"

#include "DecEffect.h"

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
	TextureManager tex;
	DecEffect decEffect;

	sf::Sprite m_bg;
	sf::Texture m_tex;
};