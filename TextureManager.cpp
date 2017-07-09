#include "TextureManager.h"

map<string, sf::Texture> TextureManager::m_texture;

TextureManager::TextureManager()
{
}


TextureManager::~TextureManager()
{
}

void TextureManager::Loading() {
	//フェード用　黒
	m_texture.insert(map<string, sf::Texture>::value_type("black", sf::Texture()));
	m_texture["black"].loadFromFile("data/image/black.png");

	//タイトル
	m_texture.insert(map<string, sf::Texture>::value_type("title_bg", sf::Texture()));
	m_texture["title_bg"].loadFromFile("data/image/title/bg.png");

	m_texture.insert(map<string, sf::Texture>::value_type("title_ring", sf::Texture()));
	m_texture["title_ring"].loadFromFile("data/image/title/ring.png");
	
	m_texture.insert(map<string, sf::Texture>::value_type("title_ring_sub", sf::Texture()));
	m_texture["title_ring_sub"].loadFromFile("data/image/title/ring_sub.png");
	
	m_texture.insert(map<string, sf::Texture>::value_type("title_logo", sf::Texture()));
	m_texture["title_logo"].loadFromFile("data/image/title/logo.png");
	
	m_texture.insert(map<string, sf::Texture>::value_type("title_logo_blur", sf::Texture()));
	m_texture["title_logo_blur"].loadFromFile("data/image/title/logo_b.png");
	
	m_texture.insert(map<string, sf::Texture>::value_type("title_select", sf::Texture()));
	m_texture["title_select"].loadFromFile("data/image/title/select_line.png");

	//セレクト
	m_texture.insert(map<string, sf::Texture>::value_type("select_use_color", sf::Texture()));
	m_texture["select_use_color"].loadFromFile("data/image/Select/use_color.png");

	m_texture.insert(map<string, sf::Texture>::value_type("select_jacket_cover", sf::Texture()));
	m_texture["select_jacket_cover"].loadFromFile("data/image/Select/jacket_cover.png");

	//ゲーム
	m_texture.insert(map<string, sf::Texture>::value_type("game_note", sf::Texture()));
	m_texture["game_note"].loadFromFile("data/image/Game/note.png");

	m_texture.insert(map<string, sf::Texture>::value_type("game_judge_line", sf::Texture()));
	m_texture["game_judge_line"].loadFromFile("data/image/Game/judge_line.png");

	//リザルト
}

sf::Texture& TextureManager::get(string key) {
	return m_texture[key];
}