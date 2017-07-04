#pragma once
#include "SFML\Graphics.hpp"
#include <fstream>
#include <cassert>
#include "picojson.h"

using namespace std;

class ConfigManager
{
public:
	ConfigManager();
	~ConfigManager();

	void DataLoading();

	//åªç›ÇÃã»(ãNìÆíÜÇÃÇ›)
	void setNowMusic(int num, int diff);
	void setNowMusicNum(int num);
	void setNowMusicDiff(int diff);
	enum MusicData { Num, Diff };
	int getNowMusic(MusicData d);

	static sf::Vector2u m_window_size;

private:
	static int m_music_num;
	static int m_music_diff;
};

