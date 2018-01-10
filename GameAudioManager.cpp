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
	//�����œn�����key�͊y�ȃf�[�^�������Ă���t�H���_��
	//�����͕Е��݂̂ł��R�[�h�Ƃ��Ă͐��藧���A������₷���̂ŕʁX��

	m_back_key = key;

	m_music.insert(make_pair(key, make_shared<sf::Music>()));//map�g��
	//key�d���̏ꍇ�͐V���ɓǂݍ��܂Ȃ�
	if (m_music.find(key) != m_music.end())
	{
		m_music[key]->openFromFile(path);//�ǂݍ���
	}
}

void GameAudioManager::start(float time, float volume, bool loop)
{
	if (m_music[m_back_key]->getStatus() != sf::SoundSource::Status::Playing) {//���ɍĐ�����Ă���Ƃ��̓X���[
		m_music[m_back_key]->play();//�Đ�
		m_music[m_back_key]->setLoop(loop);//���[�v�ݒ�
		m_music[m_back_key]->setVolume(volume * config.getSoundValue().music * config.getSoundValue().master);//���ʐݒ�
		if(time != -1) m_music[m_back_key]->setPlayingOffset(sf::seconds(time));//�Đ��ʒu�ݒ�
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
