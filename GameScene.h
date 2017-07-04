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

enum playState {
	playBefore,
	playNow,
	playAfter,
	playStop
};

class GameScene :
	public Scene
{
public:
	GameScene();
	~GameScene();

	void initialize();
	Scene* update();
	void render();

private:
	WindowManager windowManager;
	KeyManager keyManager;
	MusicManager musicManager;
	ConfigManager config;

	vector<Note> m_note;
};