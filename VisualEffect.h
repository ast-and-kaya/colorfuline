#pragma once
#include "FFT.h"
#include <SFML/Audio.hpp>
#include "WindowManager.h"
#include "SoundValue.h"
#include "TextureManager.h"
#include "ConfigManager.h"

#include <iostream>

using namespace std;

class VisualEffect
{
public:
	VisualEffect();
	~VisualEffect();

	void initialize(string path);
	void updata(float time);
	void render();

private:
	WindowManager windowManager;
	ConfigManager config;
	TextureManager tex;

	FFT fft;
	vector<int> data;
	sf::VertexArray VA2;

	SoundValue soundValue;
	sf::RenderStates state;
	sf::Shader shader;
	sf::Sprite m_sprite;

};

