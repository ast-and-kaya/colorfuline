#pragma once
#include "FFT.h"
#include <SFML/Audio.hpp>
#include "WindowManager.h"

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

	FFT fft;

	vector<int> data;

	sf::VertexArray VA2;

};

