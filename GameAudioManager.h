#pragma once
#include "SFML\Audio.hpp"
#include <map>
#include <iostream>

using namespace std;

class GameAudioManager
{
public:
	GameAudioManager();
	~GameAudioManager();

	void Load(string key, string path);
	void start(bool loop = false);
	void pause();
	void stop();
	float getOffset();

	//static map<string, sf::Music> m_music;
	static sf::Music m_music;
	static string m_back_key;
};

