#pragma once
#include "FFT.h"
#include <SFML/Audio.hpp>
#include "WindowManager.h"
#include "TextureManager.h"
#include "ConfigManager.h"
#include "MusicManager.h"

#include "KeyJudge.h"

#include <iostream>

using namespace std;

class VisualEffect
{
public:
	VisualEffect();
	~VisualEffect();

	void initialize();
	void updata(float time);
	void render();

	void setColor(sf::Color c);

private:
	WindowManager windowManager;
	ConfigManager config;
	TextureManager tex;
	KeyJudge keyJudge;
	MusicManager musicManager;

	FFT fft;
	vector<int> data;
	sf::VertexArray m_va;

	sf::RenderStates state;
	sf::Shader shader;
	sf::Sprite m_sprite;

	int m_sound_value;

	int m_sub_color[3];
};

