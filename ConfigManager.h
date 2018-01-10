#pragma once
#include "SFML\Graphics.hpp"
#include <fstream>
#include <cassert>
#include "picojson.h"

using namespace std;

//起動時に設定ファイルからの読み込みとゲーム内の固定値を設定
//
class ConfigManager
{
public:
	ConfigManager();
	~ConfigManager();

	void DataLoading();

	void initialize();//初期値等

	struct SOUND_VALUE {
		float master; float se; float music; float tip;
	};
	struct JUDGE_FRAME {
		float great; float good; float bad;
	};
	struct RAW_SCORE {
		int great; int good; int bad;
	};

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
	JUDGE_FRAME getJudgeFrame();//判定時間
	int getBlackTime();//暗転時間
	float getPreviewFade();//プレビュー
	RAW_SCORE getRawScore();
	SOUND_VALUE getSoundValue();

private:
	static int m_music_num;
	static int m_music_diff;

	static int m_lane_distance;
	static float m_start_margin;
	static JUDGE_FRAME m_judge_frame;

	static int m_black_time;

	static float m_preview_fade;

	static RAW_SCORE m_raw_score;

	static SOUND_VALUE m_sound_value;
};

