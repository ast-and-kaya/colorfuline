#include "ConfigManager.h"

sf::Vector2u ConfigManager::m_window_size;
int ConfigManager::m_music_num;
int ConfigManager::m_music_diff;

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

	//âÊñ ÉTÉCÉY
	double x = val.get("window_size").get("x").get<double>();
	double y = val.get("window_size").get("y").get<double>();
	m_window_size = sf::Vector2u(x, y);
}

void ConfigManager::setNowMusic(int num , int diff) {
	m_music_num = num;
	m_music_diff = diff;
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