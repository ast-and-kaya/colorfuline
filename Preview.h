#pragma once
#include "WindowManager.h"
#include "ConfigManager.h"
#include "GameAudioManager.h"
#include "MusicManager.h"
#include "KeyManager.h"

#include "NowPlaying.h"

#include "FFT.h"

class Preview
{
public:
	Preview();
	~Preview();

	void initialize();
	void update();
	void render();

	GameAudioManager getMusic();

private:
	WindowManager windowManager;
	ConfigManager config;
	GameAudioManager m_music;
	MusicManager musicManager;
	KeyManager keyManager;
	NowPlaying nowPlaying;

	int m_back_number;

	float m_start_time;
	float m_end_time;
};

