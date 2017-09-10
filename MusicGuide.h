#pragma once
#include "SFML\Graphics.hpp"
#include "WindowManager.h"
#include "ConfigManager.h"
#include "MusicManager.h"
#include "TextureManager.h"
#include <iostream>
#include <codecvt>
#include <map>

using namespace std;

class MusicGuide
{
public:
	MusicGuide();
	~MusicGuide();

	void initialize(sf::Vector2f pos = sf::Vector2f(0,0));
	void update();
	void render();

	void setColorBar(const int* a);

private:
	wstring_convert<codecvt_utf8<wchar_t>, wchar_t> cv;
	WindowManager windowManager;
	ConfigManager config;
	MusicManager musicManager;
	TextureManager tex;

	sf::Font m_font;
	static map<string, sf::Text> m_guide_text;

	static sf::Sprite m_use_color[7];//égópêF
};

