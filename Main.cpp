#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

#include "Scene.h"

#include "TestRoom.h"
#include "TitleScene.h"
#include "SelectScene.h"

using namespace std;

int main()
{
	ConfigManager config;
	config.DataLoading();
	config.initialize();

	MusicManager musicManager;
	musicManager.DataLoding();

	ScoreManager scoreManager;
	scoreManager.DataLoad();

	TextureManager tex;
	tex.Loading();

	sf::RenderWindow m_window(sf::VideoMode(config.m_window_size.x, config.m_window_size.y), "colorfuline ver.2.0", sf::Style::Close);
	m_window.setFramerateLimit(60);
	m_window.setView(sf::View(sf::FloatRect(0,0,1920,1080)));

	WindowManager windowManager;
	windowManager.setWindow(&m_window);
	windowManager.setWindowActive(true);

	Scene* m_scene;
	//m_scene = new TestRoom;
	m_scene = new TitleScene;
	m_scene->initialize();

	while (m_window.isOpen())
	{
		sf::Clock c;

		sf::Event event;

		while (m_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) m_window.close();

			if (event.type == sf::Event::LostFocus) windowManager.setWindowActive(false);
			if (event.type == sf::Event::GainedFocus) windowManager.setWindowActive(true);

		}

		Scene* next_scene = m_scene->update();
		if (m_scene != next_scene)
		{
			m_scene = next_scene;
			m_scene->initialize();
		}

		m_window.clear();

		m_scene->render();

		m_window.display();

		//cout << c.getElapsedTime().asSeconds() << endl;
	}

	return 0;
}