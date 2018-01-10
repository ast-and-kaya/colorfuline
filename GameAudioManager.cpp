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
	//引数で渡されるkeyは楽曲データが入っているフォルダ名
	//引数は片方のみでもコードとしては成り立つが、分かりやすいので別々に

	m_back_key = key;

	m_music.insert(make_pair(key, make_shared<sf::Music>()));//map拡張
	//key重複の場合は新たに読み込まない
	if (m_music.find(key) != m_music.end())
	{
		m_music[key]->openFromFile(path);//読み込み
	}
}

void GameAudioManager::start(float time, float volume, bool loop)
{
	if (m_music[m_back_key]->getStatus() != sf::SoundSource::Status::Playing) {//既に再生されているときはスルー
		m_music[m_back_key]->play();//再生
		m_music[m_back_key]->setLoop(loop);//ループ設定
		m_music[m_back_key]->setVolume(volume * config.getSoundValue().music * config.getSoundValue().master);//音量設定
		if(time != -1) m_music[m_back_key]->setPlayingOffset(sf::seconds(time));//再生位置設定
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

void GameAudioManager::setOffset(float time)
{
	m_music[m_back_key]->setPlayingOffset(sf::seconds(time));
}

void GameAudioManager::setVolume(float volume)
{
	m_music[m_back_key]->setVolume(volume * config.getSoundValue().music * config.getSoundValue().master);
}

float GameAudioManager::getOffset()
{
	return m_music[m_back_key]->getPlayingOffset().asSeconds();
}

float GameAudioManager::getVolume()
{
	return m_music[m_back_key]->getVolume();
}

float GameAudioManager::getDuration()
{
	return m_music[m_back_key]->getDuration().asSeconds();
}

bool GameAudioManager::getState()
{
	return m_music[m_back_key]->getStatus();
}
