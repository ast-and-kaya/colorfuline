#include "GameAudioManager.h"

map<string, shared_ptr<sf::Music>> GameAudioManager::m_music;
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

	m_music.insert(make_pair(key, make_shared<sf::Music>()));
	if (m_music.find(key) != m_music.end())
	{
		m_music[key]->openFromFile(path);
	}
}

void GameAudioManager::start( int volume, bool loop)
{
	if (m_music[m_back_key]->getStatus() != sf::SoundSource::Status::Playing) {
		m_music[m_back_key]->play();
		m_music[m_back_key]->setLoop(loop);
		m_music[m_back_key]->setVolume(volume);
	}
}

void GameAudioManager::pause()
{
	m_music[m_back_key]->pause();
}

void GameAudioManager::stop()
{
	m_music[m_back_key]->stop();
}

float GameAudioManager::getOffset()
{
	return m_music[m_back_key]->getPlayingOffset().asSeconds();
}

float GameAudioManager::getDuration()
{
	return m_music[m_back_key]->getDuration().asSeconds();
}
