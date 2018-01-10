#include "ConfigManager.h"

sf::Vector2u ConfigManager::m_window_size;
int ConfigManager::m_music_num;
int ConfigManager::m_music_diff;

int ConfigManager::m_lane_distance;
float ConfigManager::m_start_margin;
ConfigManager::JUDGE_FRAME ConfigManager::m_judge_frame;

int ConfigManager::m_black_time;

float ConfigManager::m_preview_fade;

ConfigManager::RAW_SCORE ConfigManager::m_raw_score;

ConfigManager::SOUND_VALUE ConfigManager::m_sound_value;

ConfigManager::ConfigManager()
{
}


ConfigManager::~ConfigManager()
{
}

void ConfigManager::DataLoading() {

	ifstream fs;
	fs.open("config.json", std::ios::binary);
	assert(fs);
	picojson::value val;
	fs >> val;
	fs.close();

	//��ʃT�C�Y
	double x = val.get("window_size").get("x").get<double>();
	double y = val.get("window_size").get("y").get<double>();
	m_window_size = sf::Vector2u(x, y);
}

void ConfigManager::initialize()
{
	//��
	m_music_num = 0;
	m_music_diff = 0;

	m_lane_distance = 940;//���[���̋���
	m_start_margin = 5.0f;//�ȍĐ��܂ł̎���
	//���莞��
	float frame = 1.f / 60.f;
	m_judge_frame.great = frame * 2;//perfect
	m_judge_frame.good = frame * 6;//great
	m_judge_frame.bad = frame * 10;//good
	//�Ó]�X�s�[�h
	m_black_time = 5;
	//�v���r���[�̃t�F�[�h�b��
	m_preview_fade = 3.0f; 
	//�X�R�A�@�f�_
	m_raw_score.great = 300;
	m_raw_score.good = 250;
	m_raw_score.bad = 100;
	//����
	m_sound_value.master = 0.f;
	m_sound_value.se = 1.f;
	m_sound_value.music = 1.f;
	m_sound_value.tip = 1.f;
}

void ConfigManager::setNowMusicNum(int num) {
	m_music_num = num;
}
void ConfigManager::setNowMusicDiff(int diff) {
	m_music_diff = diff;
}

int ConfigManager::getNowMusic(MusicData d) {
	if (d == Num) return m_music_num;
	if (d == Diff) return m_music_diff;
}

int ConfigManager::getLaneDistance()
{
	return m_lane_distance;
}

float ConfigManager::getStartMargin()
{
	return m_start_margin;
}

ConfigManager::JUDGE_FRAME ConfigManager::getJudgeFrame()
{
	return m_judge_frame;
}

int ConfigManager::getBlackTime()
{
	return m_black_time;
}

float ConfigManager::getPreviewFade()
{
	return m_preview_fade;
}

ConfigManager::RAW_SCORE ConfigManager::getRawScore()
{
	return m_raw_score;
}

ConfigManager::SOUND_VALUE ConfigManager::getSoundValue()
{
	return m_sound_value;
}
