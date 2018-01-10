#pragma once
#include "SFML\Graphics.hpp"
#include <fstream>
#include <cassert>
#include "picojson.h"

using namespace std;

//�N�����ɐݒ�t�@�C������̓ǂݍ��݂ƃQ�[�����̌Œ�l��ݒ�
//
class ConfigManager
{
public:
	ConfigManager();
	~ConfigManager();

	void DataLoading();

	void initialize();//�����l��

	struct SOUND_VALUE {
		float master; float se; float music; float tip;
	};
	struct JUDGE_FRAME {
		float great; float good; float bad;
	};
	struct RAW_SCORE {
		int great; int good; int bad;
	};

	//���݂̋�(�N�����̂�)
	void setNowMusicNum(int num);
	void setNowMusicDiff(int diff);
	enum MusicData { Num, Diff };
	int getNowMusic(MusicData d);

	//�E�B���h�E�T�C�Y
	static sf::Vector2u m_window_size;

	//�Œ�l
	int getLaneDistance();//���[������
	float getStartMargin();//�ȊJ�n�O�̃}�[�W��
	JUDGE_FRAME getJudgeFrame();//���莞��
	int getBlackTime();//�Ó]����
	float getPreviewFade();//�v���r���[
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

