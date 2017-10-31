#pragma once
#include "WindowManager.h"
#include <SFML/Graphics.hpp>
#include "TextureManager.h"
#include "ConfigManager.h"

using namespace std;

class Note
{
public:
	Note();
	~Note();

	void setNote(float sec, sf::Color color);
	void update(float music_offset);
	void render();

	int judge(float sec, sf::Color color);// 0:miss 1:perfect 2:great 3:good 
	bool rangeOut(float sec);

	float getSec();

private:
	WindowManager windowManager;
	TextureManager tex;
	ConfigManager config;

	float lerp(float s, float e, float t);

	sf::Sprite m_sprite;

	float m_sec;
	sf::Color m_color;

	sf::Shader m_shad;
	sf::RenderStates m_state;
};