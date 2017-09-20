#include "Preview.h"



Preview::Preview()
{
}


Preview::~Preview()
{
}

void Preview::initialize()
{
	m_back_number = -1;

	m_start_time = 0;
	m_end_time = 0;

	VA2.setPrimitiveType(sf::Lines);

	nowPlaying.initialize( sf::Vector2f(960, 83.f * 6.f), 0.15f, sf::Color::Black);
}

void Preview::update()
{
	if (m_back_number != config.getNowMusic(config.Num))
	{
		if (m_back_number != -1) m_music.stop();

		m_back_number = config.getNowMusic(config.Num);

		m_start_time = musicManager.getItem(m_back_number).preview[0];
		m_end_time = musicManager.getItem(m_back_number).preview[1];

		string folder_name = musicManager.getFolderList(config.getNowMusic(config.Num));
		m_music.Load(folder_name, "data/music/" + folder_name + "/music.ogg");
		m_music.start(m_start_time, 0.0f);

		fft.init(config.getNowMusic(config.Num));

		nowPlaying.reset();
	} 

	if (m_music.getOffset() - m_start_time < config.getPreviewFade())
	{
		m_music.setVolume(m_music.getVolume() + (2.0f / (60 * config.getPreviewFade())));
	}

	if (m_end_time - config.getPreviewFade() < m_music.getOffset())
	{
		m_music.setVolume(m_music.getVolume() - (2.0f / (60 * config.getPreviewFade())));
	}

	if (m_music.getOffset() > m_end_time)
	{
		m_music.setOffset(m_start_time);
		m_music.setVolume(0);
	}

	//fft
	fft.update(m_music.getOffset());

	data = fft.getData();

	VA2.clear();
	sf::Vector2f position( 0, 540);
	sf::Color c[3] = {
		sf::Color(0,255,255,0),//c
		sf::Color(255,255,0,0),//y
		sf::Color(255,0,255,0) //m
	};
	for (int i = 0; i < data.size(); i++)
	{
		VA2.append(sf::Vertex(position + sf::Vector2f(i * 4.6, -data[i] / 200000), sf::Color(255, 255, 255, 200)));
		VA2.append(sf::Vertex(position + sf::Vector2f(i * 4.6, 0), c[config.getNowMusic(config.Diff)]));
		VA2.append(sf::Vertex(position + sf::Vector2f(i * 4.6, 0), c[config.getNowMusic(config.Diff)]));
		VA2.append(sf::Vertex(position + sf::Vector2f(i * 4.6, data[i] / 200000), sf::Color(255,255,255,200)));
	}

	nowPlaying.update(2.0f);
}

void Preview::render()
{
	windowManager.getWindow()->draw(VA2);
	nowPlaying.render();
}

GameAudioManager Preview::getMusic()
{
	return m_music;
}
