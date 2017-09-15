#include "ConfigManager.h"

sf::Vector2u ConfigManager::m_window_size;
int ConfigManager::m_music_num;
int ConfigManager::m_music_diff;

int ConfigManager::m_lane_distance;
float ConfigManager::m_start_margin;
float ConfigManager::m_judge_frame[3];

int ConfigManager::m_black_time;

float ConfigManager::m_preview_fade;

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

	//画面サイズ
	double x = val.get("window_size").get("x").get<double>();
	double y = val.get("window_size").get("y").get<double>();
	m_window_size = sf::Vector2u(x, y);
}

void ConfigManager::initialize()
{
	m_music_num = 0;
	m_music_diff = 0;

	//マジックナンバー
	m_lane_distance = 940;//レーンの距離
	m_start_margin = 3.0f;//
	//判定時間
	float frame = 1.f / 60.f;
	m_judge_frame[0] = frame * 2;//perfect
	m_judge_frame[1] = frame * 6;//great
	m_judge_frame[2] = frame * 10;//good
	//暗転スピード
	m_black_time = 5;
	//プレビューのフェード秒数
	m_preview_fade = 3.0f;
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

float ConfigManager::getJudgeFrame(int f)
{
	return m_judge_frame[f];
}

int ConfigManager::getBlackTime()
{
	return m_black_time;
}

float ConfigManager::getPreviewFade()
{
	return m_preview_fade;
}
