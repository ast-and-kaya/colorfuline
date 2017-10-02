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
	sf::Color c[8] = {
		sf::Color::Transparent,
		sf::Color::Blue,
		sf::Color::Green,
		sf::Color::Cyan,
		sf::Color::Red,
		sf::Color::Magenta,
		sf::Color::Yellow,
		sf::Color::White 
	};

	string diff[3] = { "easy", "normal", "hard"};

	m_path = "data/music/" + musicManager.getFolderList(config.getNowMusic(config.Num)) + "/music_score.cfl";

	ifstream fs;
	fs.open(m_path, std::ios::binary);
	assert(fs);
	picojson::value val;
	cout << val << endl;
	fs >> val;
	fs.close();

	for (int i = 0; i < val.get(diff[config.getNowMusic(config.Diff)]).get<picojson::array>().size(); i++) {
		m_data.push_back(Data());
		m_data[i].time = val.
			get(diff[config.getNowMusic(config.Diff)]).
			get(i).get(0).
			get<double>();
		m_data[i].color = c[(int)val.
			get(diff[config.getNowMusic(config.Diff)]).
			get(i).get(1).
			get<double>()];
	}

	//for (int i = 0; i < 1000; i++) {
	//	m_data.push_back(Data());
	//	m_data[i].time = i*(60.f / 162.f) + 0.1;
	//	m_data[i].color =  c[rand() % 3];
	//}
}

MusicScore::Data MusicScore::getData(int num)
{
	return m_data[num];
}

int MusicScore::getSize()
{
	return m_data.size();
}
