#pragma once
#include "SFML\Audio.hpp"
#include <map>
#include <iostream>
#include <memory>
#include "ConfigManager.h"

using namespace std;

//楽曲用の再生クラス
//起動時以降、一度読み込まれた音楽ファイルは再読み込みしない
//セレクトシーンのpre時に少し重くなってしまう
//一度読み込んでしまえば後は軽い
class GameAudioManager
{
public:
	GameAudioManager();
	~GameAudioManager();

	void Load(string key, string path);//曲のローディング
	//再生に関する関数
	void start(float time = -1,float volume = 2.0f, bool loop = false);
	void pause();
	void stop();

	void setOffset(float time);
	void setVolume(float volume);

	float getOffset();
	float getVolume();
	float getDuration();//曲長さ
	bool getState();

private:
	ConfigManager config;

	static map<string, std::shared_ptr<sf::Music>> m_music;
	static string m_back_key;
};

