#pragma once
class Scene;
#include "KeyManager.h"
#include "WindowManager.h"
#include <SFML\Graphics.hpp> 
#include "TextureManager.h"
#include "SceneMovement.h"

#include "CharacterDisplay.h"

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
	CharacterDisplay characterDisplay;

	int m_select_cursor;
	sf::Vector2f TextPos;

	sf::Sprite m_bg;

	sf::RenderStates m_state;
	sf::Shader m_shad;

	sf::Clock m_clock;
};

