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


	nowPlaying.update(2.0f);
}

void Preview::render()
{
	nowPlaying.render();
}

GameAudioManager Preview::getMusic()
{
	return m_music;
}
