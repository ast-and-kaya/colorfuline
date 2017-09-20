#include "LoadingScene.h"

#include "TitleScene.h"

LoadingScene::LoadingScene()
{
}


LoadingScene::~LoadingScene()
{
}

void LoadingScene::initialize()
{
	thread = new sf::Thread([&]() {this->load(); });
	thread->launch();

	m_bg.setTexture(tex.get("loading_bg"));

	for (int i = 0; i < 5; i++)
	{
		m_rote[i].setTexture(tex.get("loading_rote"));
		m_rote[i].setOrigin(tex.get("loading_rote").getSize().x / 2.0, tex.get("loading_rote").getSize().y / 2.0);
		m_rote[i].setPosition(sf::Vector2f(1380,980));
		m_rote[i].setScale(0.18, 0.18);
	}

	m_bar.setPrimitiveType(sf::Quads);

	characterDisplay.setFont("Dosis", "data/font/Dosis-Light.ttf");
	characterDisplay.setCharacter("colorfuline", "Dosis", "colorfuline", sf::Vector2f(50, 10), 150);
	characterDisplay.setCharacter("loading", "Dosis", "Now Loading", sf::Vector2f(1880, 920), 90);
	characterDisplay.setOrigin("loading", CharacterDisplay::Align::Right);
}

Scene * LoadingScene::update()
{
	Scene* next = this;

	for (int i = 0; i < 5; i++)
	{
		m_rote[i].setRotation(m_rote[i].getRotation() + (i + 1)*2);
	}


	float bar_cnt = m_cnt * 20.f / musicManager.getItemNumber();
	m_bar.clear();
	for (int i = 0; i < 20; i++)
	{
		sf::Vector2f position(460 + i * 50, 490);
		int alpha = (i >= bar_cnt) ? 20 : 150;

		m_bar.append(sf::Vertex(position + sf::Vector2f(0, 0), sf::Color(255, 255, 255, alpha)));
		m_bar.append(sf::Vertex(position + sf::Vector2f(40, 0), sf::Color(255, 255, 255, alpha)));
		m_bar.append(sf::Vertex(position + sf::Vector2f(40, 100), sf::Color(255, 255, 255, alpha)));
		m_bar.append(sf::Vertex(position + sf::Vector2f(0, 100), sf::Color(255, 255, 255, alpha)));
	}


	if (m_scene_move)
	{
		fft.setBufferData(m_buffer);
		next = new TitleScene;
	}
	if (m_cnt == musicManager.getItemNumber())
	{
		m_scene_move = true;
	}

	return next;
}

void LoadingScene::render()
{
	windowManager.getWindow()->draw(m_bg);
	characterDisplay.render("colorfuline");
	characterDisplay.render("loading");

	windowManager.getWindow()->draw(m_bar);

	for (int i = 0; i < 5; i++) windowManager.getWindow()->draw(m_rote[i]);
}

void LoadingScene::load()
{
	for (int i = 0; i < musicManager.getItemNumber(); i++)
	{
		sf::SoundBuffer b;
		string path = "data/music/" + musicManager.getFolderList(i) + "/music.ogg";
		b.loadFromFile(path);

		m_buffer.push_back(b);
		
		m_cnt++;
	}
}
