#pragma once

#include "Scene.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "SelectScene.h"
#include "SceneMovement.h"

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

	sf::Sprite m_bg;

	sf::Sprite m_ring;

	float m_ring_alpha;

	sf::RenderStates m_rs_ring;
	sf::Shader m_shad_ring;

	//���S
	sf::Sprite m_logo;
	//���S�@�ڂ���
	sf::Sprite m_logo_blur;
	sf::Clock blur_clock;

	//�t�F�[�h�p�@��
	sf::Sprite m_black;
	int m_black_alpha;

	//����
	sf::Font font;
	sf::Text m_txt_start;
	sf::Text m_txt_exit;
	//�Z���N�g�o�[
	sf::Sprite m_select;
	bool m_select_tf;
	int m_select_posx[2];
};

