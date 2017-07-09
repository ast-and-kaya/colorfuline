#include "GameAudioManager.h"

//map<string, sf::Music> GameAudioManager::m_music;
sf::Music GameAudioManager::m_music;
string GameAudioManager::m_back_key;

GameAudioManager::GameAudioManager()
{
}


GameAudioManager::~GameAudioManager()
{
}

void GameAudioManager::Load(string key, string path)
{
	m_back_key = key;
	m_music.openFromFile(path);
	//m_music.insert(map<string, sf::Music>::value_type(key, sf::Music()));
	//if (m_music.find(key) == m_music.end())
	//{
	//	m_music[key].openFromFile(path);
	//}
}

void GameAudioManager::start( int volume, bool loop)
{
	m_music.play();
	m_music.setLoop(loop);
	m_music.setVolume(volume);
	//m_music[m_back_key].play();
	//m_music[m_back_key].setLoop(loop);
	//m_music[m_back_key].setVolume(volume);
}

void GameAudioManager::pause()
{
	m_music.pause();
	//m_music[m_back_key].pause();
}

void GameAudioManager::stop()
{
	m_music.stop();
	//m_music[m_back_key].stop();
}

float GameAudioManager::getOffset()
{
	//cout << m_music.getPlayingOffset().asSeconds() << endl;
	return m_music.getPlayingOffset().asSeconds();
	//return m_music[m_back_key].getPlayingOffset().asSeconds();
}
