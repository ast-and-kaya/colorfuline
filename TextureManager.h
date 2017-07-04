#pragma once
#include <map>
#include "SFML\Graphics.hpp"

using namespace std;

class TextureManager
{
public:
	TextureManager();
	~TextureManager();

	void Loading();
	sf::Texture& get(string key);

	static map<string, sf::Texture> m_texture;
};

