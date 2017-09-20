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

	//ロード
	m_texture.insert(map<string, sf::Texture>::value_type("loading_bg", sf::Texture()));
	m_texture["loading_bg"].loadFromFile("data/image/Loading/background.png");
	m_texture.insert(map<string, sf::Texture>::value_type("loading_rote", sf::Texture()));
	m_texture["loading_rote"].loadFromFile("data/image/Loading/rote.png");

	//タイトル
	m_texture.insert(map<string, sf::Texture>::value_type("title_logo", sf::Texture()));
	m_texture["title_logo"].loadFromFile("data/image/title/logo.png");
	
	m_texture.insert(map<string, sf::Texture>::value_type("title_logo_blur", sf::Texture()));
	m_texture["title_logo_blur"].loadFromFile("data/image/title/logo_b.png");
	
	m_texture.insert(map<string, sf::Texture>::value_type("title_select", sf::Texture()));
	m_texture["title_select"].loadFromFile("data/image/title/select_line.png");

	//セレクト
	m_texture.insert(map<string, sf::Texture>::value_type("select_use_color", sf::Texture()));
	m_texture["select_use_color"].loadFromFile("data/image/Select/use_color.png");

	m_texture.insert(map<string, sf::Texture>::value_type("select_loading0", sf::Texture()));
	m_texture["select_loading0"].loadFromFile("data/image/Select/loading0.png");

	m_texture.insert(map<string, sf::Texture>::value_type("select_loading1", sf::Texture()));
	m_texture["select_loading1"].loadFromFile("data/image/Select/loading1.png");

	//ゲーム
	m_texture.insert(map<string, sf::Texture>::value_type("game_note", sf::Texture()));
	m_texture["game_note"].loadFromFile("data/image/Game/note.png");

	m_texture.insert(map<string, sf::Texture>::value_type("game_judge_line", sf::Texture()));
	m_texture["game_judge_line"].loadFromFile("data/image/Game/judge_line.png");

	m_texture.insert(map<string, sf::Texture>::value_type("game_judge_line_sub", sf::Texture()));
	m_texture["game_judge_line_sub"].loadFromFile("data/image/Game/judge_line_sub.png");

	//リザルト
	m_texture.insert(map<string, sf::Texture>::value_type("result_select", sf::Texture()));
	m_texture["result_select"].loadFromFile("data/image/result/select_line.png");

	for (auto& it : m_texture)
	{
		it.second.setSmooth(true);
	}
}

sf::Texture& TextureManager::get(string key) {
	return m_texture[key];
}