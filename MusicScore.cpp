#include "MusicScore.h"

namespace {

}

MusicScore::MusicScore()
{
}


MusicScore::~MusicScore()
{
}

void MusicScore::Loading()
{
	sf::Color c[7] = { sf::Color::Red, sf::Color::Green, sf::Color::Blue,
		sf::Color::Cyan, sf::Color::Magenta, sf::Color::Yellow,
		sf::Color::White };

	string diff[3] = { "easy", "normal", "hard"};

	m_path = "data/music/" + musicManager.getFolderList(config.getNowMusic(config.Num)) + "/score_" + diff[config.getNowMusic(config.Diff)] + ".json";

	for (int i = 0; i < 100; i++) {
		m_data.push_back(Data());
		m_data[i].time = i*(60.f / 162.f) + 0.1;
		m_data[i].color =  c[rand() % 3];
	}
}

MusicScore::Data MusicScore::getData(int num)
{
	return m_data[num];
}

int MusicScore::getSize()
{
	return m_data.size();
}
