#pragma once
#include <map>
#include "SFML\Graphics.hpp"
#include "SFML\Audio.hpp"

using namespace std;

//�g�p����e�N�X�`�����ꊇ�ǂݍ���
//�g�p����ۂ̓Q�b�^����
//�y�Ȃ̃W���P�b�g�͗�O
class TextureManager
{
public:
	TextureManager();
	~TextureManager();

	void Loading();//�ǂݍ���
	sf::Texture& get(string key);//�Ăяo��

	static map<string, sf::Texture> m_texture;
};

