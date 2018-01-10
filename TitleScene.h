#pragma once

#include "Scene.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "SelectScene.h"
#include "SceneMovement.h"
#include "ConfigManager.h"

//�^�C�g��
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

	//���S
	sf::Sprite m_logo;
	//���S�@�ڂ���
	sf::Sprite m_logo_blur;

	//����
	sf::Font font;
	sf::Text m_txt_start;
	sf::Text m_txt_exit;
	//�Z���N�g�o�[
	sf::Sprite m_select;
	bool m_select_tf;
	int m_select_posx[2];
};

