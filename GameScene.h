#pragma once
#include <SFML/Audio.hpp>
#include <iostream>
#include <codecvt>
#include <vector>

#include "Scene.h"

#include "MusicManager.h"
#include "ConfigManager.h"
#include "GameAudioManager.h"

#include "Note.h"
#include "Pause.h"

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
	Pause pause;

	//ÉQÅ[ÉÄÇÃèÛë‘Å@0:before 1:now 2:after 3:stop
	int m_game_state;

	float m_start_margin;
	sf::Clock m_clock;

	vector<Note> m_note;

	sf::Sprite m_judge_line;
};