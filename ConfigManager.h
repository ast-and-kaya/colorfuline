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

	void initialize();//マジックナンバー・他初期値

	//現在の曲(起動中のみ)
	void setNowMusicNum(int num);
	void setNowMusicDiff(int diff);
	enum MusicData { Num, Diff };
	int getNowMusic(MusicData d);

	//ウィンドウサイズ
	static sf::Vector2u m_window_size;

	//固定値
	int getLaneDistance();
	float getStartMargin();
	float getJudgeFrame(int f);

private:
	static int m_music_num;
	static int m_music_diff;

	static int m_lane_distance;
	static float m_start_margin;
	static float m_judge_frame[3];// 1:perfect 2:great 3:good
};

