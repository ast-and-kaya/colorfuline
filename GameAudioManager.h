#pragma once
#include "SFML\Audio.hpp"
#include <map>
#include <iostream>
#include <memory>

using namespace std;

class GameAudioManager
{
public:
	GameAudioManager();
	~GameAudioManager();

	void Load(string key, string path);
	void start(int volume = 1.0f, bool loop = true);
	void pause();
	void stop();
	float getOffset();

	static map<string, std::shared_ptr<sf::Music>> m_music;
	static string m_back_key;
};

