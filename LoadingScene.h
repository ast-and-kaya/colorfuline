#pragma once
#include <SFML/Audio.hpp>
#include "Scene.h"
#include <iostream>

#include "TextureManager.h"
#include "MusicManager.h"
#include "CharacterDisplay.h"

#include "FFT.h"

using namespace std;

class LoadingScene :
	public Scene
{
public:
	LoadingScene();
	~LoadingScene();

	void initialize();
	Scene* update();
	void render();

	void load();

private:
	WindowManager windowManager;
	KeyManager keyManager;
	TextureManager tex;
	MusicManager musicManager;
	CharacterDisplay characterDisplay;
	FFT fft;

	sf::Thread* thread;

	//‰æ‘œ‚Æ‚©
	sf::Sprite m_bg;
	sf::Sprite m_rote[5];

	sf::VertexArray m_bar;

	vector<sf::SoundBuffer> m_buffer;

	int m_cnt;
	int m_amount;

	bool m_scene_move;
};