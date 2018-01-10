#pragma once

#include "Scene.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "SelectScene.h"
#include "SceneMovement.h"
#include "ConfigManager.h"

//タイトル
//
class TitleScene:
	public Scene
{
public:
	TitleScene();
	~TitleScene();

	void initialize();
	Scene* update();
	void render();

private:
	WindowManager windowManager;
	KeyManager keyManager;
	TextureManager tex;
	SceneMovement sceneMovement;
	ConfigManager config;

	sf::Sprite m_bg;
	sf::RenderStates m_bg_state;
	sf::Shader m_bg_shad;
	sf::Clock m_clock;

	//ロゴ
	sf::Sprite m_logo;
	//ロゴ　ぼかし
	sf::Sprite m_logo_blur;

	//文字
	sf::Font font;
	sf::Text m_txt_start;
	sf::Text m_txt_exit;
	//セレクトバー
	sf::Sprite m_select;
	bool m_select_tf;
	int m_select_posx[2];
};

