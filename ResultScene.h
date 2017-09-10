#pragma once
#include <SFML/Audio.hpp>
#include "Scene.h"
#include "GameScene.h"
#include "SelectScene.h"
#include <iostream>
#include <codecvt>

#include "MusicManager.h"
#include "ConfigManager.h"
#include "ScoreManager.h"
#include "TextureManager.h"

#include "CharacterDisplay.h"

#include "SceneMovement.h"
#include "MusicGuide.h"

using namespace std;

class ResultScene :
	public Scene
{
public:
	ResultScene();
	~ResultScene();

	void initialize();
	Scene* update();
	void render();

	void setScereData(float score, int combo, int perfect, int note);

private:
	WindowManager windowManager;
	KeyManager keyManager;
	MusicManager musicManager;
	TextureManager tex;
	ConfigManager config;
	CharacterDisplay characterDisplay;
	SceneMovement sceneMovement;
	MusicGuide musicGuide;

	static float m_result_score;
	static int m_result_combo;
	static int m_result_perfect;

	static int m_result_note_number;

	sf::Sprite m_bg;

	sf::Shader m_shad;
	sf::RenderStates m_state;
	
	//セレクトバー
	sf::Sprite m_select;
	bool m_select_tf; // t:select f:retry
	int m_select_posx[2];
};