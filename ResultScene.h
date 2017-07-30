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

#include "CharacterDisplay.h"

#include "SceneMovement.h"

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

	void setScereData(int score, int combo, int perfect, int note);

private:
	WindowManager windowManager;
	KeyManager keyManager;
	MusicManager musicManager;
	ConfigManager config;
	CharacterDisplay characterDisplay;
	SceneMovement sceneMovement;

	static int m_result_score;
	static int m_result_combo;
	static int m_result_perfect;

	static int m_result_note_number;

};