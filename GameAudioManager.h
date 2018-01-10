#pragma once
#include "SFML\Audio.hpp"
#include <map>
#include <iostream>
#include <memory>
#include "ConfigManager.h"

using namespace std;

//�y�ȗp�̍Đ��N���X
//�N�����ȍ~�A��x�ǂݍ��܂ꂽ���y�t�@�C���͍ēǂݍ��݂��Ȃ�
//�Z���N�g�V�[����pre���ɏ����d���Ȃ��Ă��܂�
//��x�ǂݍ���ł��܂��Ό�͌y��
class GameAudioManager
{
public:
	GameAudioManager();
	~GameAudioManager();

	void Load(string key, string path);//�Ȃ̃��[�f�B���O
	//�Đ��Ɋւ���֐�
	void start(float time = -1,float volume = 2.0f, bool loop = false);
	void pause();
	void stop();

	void setOffset(float time);
	void setVolume(float volume);

	float getOffset();
	float getVolume();
	float getDuration();//�Ȓ���
	bool getState();

private:
	ConfigManager config;

	static map<string, std::shared_ptr<sf::Music>> m_music;
	static string m_back_key;
};

