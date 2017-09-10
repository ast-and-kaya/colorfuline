#pragma once
#include "SFML\Graphics.hpp"
#include "WindowManager.h"
#include "TextureManager.h"

class NowPlaying
{
public:
	NowPlaying();
	~NowPlaying();

	void initialize(sf::Vector2f pos, float size, sf::Color color);
	void update(float speed = 1.0f);
	void render();

	void reset();

private:
	WindowManager windowManager;
	TextureManager tex;

	sf::Sprite sprite[5];
	sf::Sprite sprite2;
};

