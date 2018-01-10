#pragma once
#include <map>
#include "SFML\Graphics.hpp"
#include "SFML\Audio.hpp"

using namespace std;

//使用するテクスチャを一括読み込み
//使用する際はゲッタから
//楽曲のジャケットは例外
class TextureManager
{
public:
	TextureManager();
	~TextureManager();

	void Loading();//読み込み
	sf::Texture& get(string key);//呼び出し

	static map<string, sf::Texture> m_texture;
};

