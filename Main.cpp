#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

#include "Scene.h"

#include "TestRoom.h"
#include "TitleScene.h"
#include "LoadingScene.h"

using namespace std;

//�g�p���C�u�����F SFML-2.3.2 / picojson
int main()
{
	//�R���t�B�O
	ConfigManager config;
	config.DataLoading();
	config.initialize();

	//�y�ȃf�[�^
	MusicManager musicManager;
	musicManager.DataLoding();

	//�n�C�X�R�A�f�[�^
	ScoreManager scoreManager;
	scoreManager.DataLoad();

	//�Q�[�����e�N�X�`��
	TextureManager textureManager;
	textureManager.Loading();

	//SFML�ŃE�B���h�E�̍쐬�Ɛݒ�
	sf::RenderWindow m_window(sf::VideoMode(config.m_window_size.x, config.m_window_size.y), "colorfuline ver.2.0", sf::Style::Close);
	m_window.setFramerateLimit(60);
	m_window.setView(sf::View(sf::FloatRect(0,0,1920,1080)));

	//�E�B���h�E��static�ŕێ��@���̑��E�B���h�E�̋@�\�p
	WindowManager windowManager;
	windowManager.setWindow(&m_window);
	windowManager.setWindowActive(true);

	//�V�[���̐؂�ւ��p�N���X
	Scene* m_scene;
	m_scene = new TitleScene;
	m_scene->initialize();

	//���C�����[�v
	while (m_window.isOpen())
	{
		sf::Clock c;//�������Ԃ̃f�o�b�O�p

		sf::Event event;//sfml�C�x���g

		while (m_window.pollEvent(event))//�E�B���h�E�C�x���g
		{
			if (event.type == sf::Event::Closed) m_window.close();//����

			//�E�B���h�E�̃A�N�e�B�u���m
			if (event.type == sf::Event::LostFocus) windowManager.setWindowActive(false);
			if (event.type == sf::Event::GainedFocus) windowManager.setWindowActive(true);

		}

		//�V�[����update�Ɛ؂�ւ��
		Scene* next_scene = m_scene->update();
		if (m_scene != next_scene)
		{
			m_scene = next_scene;
			m_scene->initialize();
		}

		m_window.clear();//����

		m_scene->render();//�V�[���̃����_�����O

		m_window.display();//�`��


	}

	return 0;
}