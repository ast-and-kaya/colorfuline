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
	int getLaneDistance();//レーン距離
	float getStartMargin();//曲開始前のマージン
	float getJudgeFrame(int f);//判定時間
	int getBlackTime();//暗転時間


private:
	static int m_music_num;
	static int m_music_diff;

	static int m_lane_distance;
	static float m_start_margin;
	static float m_judge_frame[3];// 1:perfect 2:great 3:good

	static int m_black_time;
};

