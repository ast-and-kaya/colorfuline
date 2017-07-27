#pragma once
#include <SFML\Graphics.hpp>
#include "TextureManager.h"
#include "WindowManager.h"
#include <iostream>

using namespace std;

class SceneMovement
{
public:
	SceneMovement();
	~SceneMovement();

	void initialize();

	float update();

	void In();
	void Out();

private:
	WindowManager windowManager;
	TextureManager tex;

	float m_alpha;

	bool m_in_out;
};

