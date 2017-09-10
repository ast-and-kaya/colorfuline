#pragma once
#include <SFML/Audio.hpp>
#include <iostream>
#include <codecvt>
#include <vector>

#include "Scene.h"

#include "MusicManager.h"
#include "ConfigManager.h"
#include "GameAudioManager.h"
#include "KeyJudge.h"
#include "SupportLine.h"
#include "CharacterDisplay.h"
#include "GameTimer.h"
#include "JudgeLine.h"
#include "VisualEffect.h"
#include "MusicGuide.h"
#include "MusicScore.h"

#include "Note.h"
#include "Pause.h"
#include "SceneMovement.h"

using namespace std;

class GameScene :
	public Scene
{
public:
	GameScene();
	~GameScene();

	void initialize();
	Scene* update();
	void render();

	void playBefore();
	void playNow();
	void playAfter(Scene*& n);

private:
	WindowManager windowManager;
	KeyManager keyManager;
	MusicManager musicManager;
	TextureManager tex;
	GameAudioManager m_music;
	ConfigManager config;
	KeyJudge keyJudge;
	Pause pause;
	SupportLine supportLine;
	CharacterDisplay characterDisplay;
	GameTimer timer;
	SceneMovement sceneMovement;
	JudgeLine judgeLine;
	VisualEffect visualEffect;
	MusicGuide musicGuide;
	MusicScore musicScore;

	//ゲームの状態　0:before 1:now 2:after 3:stop
	int m_game_state;

	float m_score;
	int m_perfect;
	int m_maxcombo;

	int m_combo;

	vector<Note> m_note;

	bool m_black_zindex;
};