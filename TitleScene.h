#pragma once

#include "Scene.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "SelectScene.h"

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

	sf::Sprite m_bg;

	sf::Sprite m_ring;

	float m_ring_alpha;

	sf::RenderStates m_rs_ring;
	sf::Shader m_shad_ring;

	//ロゴ
	sf::Sprite m_logo;
	//ロゴ　ぼかし
	sf::Sprite m_logo_blur;
	sf::Clock blur_clock;

	//フェード用　黒
	sf::Sprite m_black;
	int m_black_alpha;

	//シーン移動用　黒　
	sf::Sprite m_enter_black;
	int m_enter_black_alpha;
	bool m_enter_black_alpha_tf;

	//文字
	sf::Font font;
	sf::Text m_txt_start;
	sf::Text m_txt_exit;
	//セレクトバー
	sf::Sprite m_select;
	bool m_select_tf;
	int m_select_posx[2];
};

