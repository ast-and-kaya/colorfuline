#pragma once
#include <SFML/Audio.hpp>
#include "Scene.h"
#include "GameScene.h"
#include "TitleScene.h"

#include <iostream>
#include <codecvt>

#include "ScoreManager.h"
#include "SceneMovement.h"

using namespace std;

class SelectScene :
	public Scene
{
public:
	SelectScene();
	~SelectScene();

	void initialize();
	Scene* update();
	void render();

	void setColorBar(const int* a);

private:
	wstring_convert<codecvt_utf8<wchar_t>, wchar_t> cv;
	WindowManager windowManager;
	KeyManager keyManager;
	MusicManager musicManager;
	ConfigManager config;
	ScoreManager scoreManager;
	TextureManager tex;
	CharacterDisplay characterDisplay;
	SceneMovement sceneMovement;

	//フォント
	sf::Font m_font_list;

	//曲名リスト
	vector<sf::Text> m_list;

	//曲選択
	sf::Vector2f m_list_pos;
	int m_s_move;

	sf::Sprite m_list_bg;
	sf::Shader m_shad_list_bg;
	sf::RenderStates m_state_list_bg;

	//難易度選択
	int m_diff;
	sf::Color m_diff_color[3];

	//曲情報
	sf::Sprite m_use_color[7];//使用色
	//サムネイル
	sf::Texture m_tex_jacket;
	sf::Sprite m_jacket;
	sf::RenderStates m_state_jacket;
	sf::Shader m_shad_jacket;

	//曲変更感知
	int m_bf_music;//前フレーム曲番号
};