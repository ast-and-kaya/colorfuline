#pragma once
#include <SFML/Graphics.hpp>

#include "WindowManager.h"
#include "KeyManager.h"
#include "MouseManager.h"
#include "ConfigManager.h"
#include "MusicManager.h"
#include "TextureManager.h"

class Scene
{
public:
	Scene();
	~Scene();

	virtual void initialize();
	virtual Scene* update();
	virtual void render();
};

