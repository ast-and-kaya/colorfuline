#pragma once
class Scene;
#include "KeyManager.h"
#include "WindowManager.h"
#include <SFML\Graphics.hpp> 
#include "TextureManager.h"
#include "SceneMovement.h"

class Pause
{
public:
	Pause();
	~Pause();

	void initialize();
	int update(Scene*& n);
	void render();

private:
	KeyManager keyManager;
	WindowManager windowManager;
	TextureManager tex;
	SceneMovement sceneMovement;

	int m_select_cursor;

	sf::Sprite m_bg;

	sf::Font m_font;
	sf::Text m_menu[3];
};

