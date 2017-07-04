#pragma once
#include <SFML/Audio.hpp>
#include "Scene.h"
#include <iostream>
#include <codecvt>

#include "MusicManager.h"
#include "ConfigManager.h"

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

	sf::Sprite s;
	sf::Texture t;
};