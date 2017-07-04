#pragma once
#include <SFML/Audio.hpp>
#include <iostream>
#include <codecvt>
#include <vector>

#include "Scene.h"
#include "ResultScene.h"

#include "MusicManager.h"
#include "ConfigManager.h"

#include "Note.h"

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
	void playAfter();
	void playStop();

private:
	WindowManager windowManager;
	KeyManager keyManager;
	MusicManager musicManager;
	ConfigManager config;

	//ÉQÅ[ÉÄÇÃèÛë‘Å@0:before 1:now 2:after 3:stop
	int m_game_state;

	vector<Note> m_note;
};