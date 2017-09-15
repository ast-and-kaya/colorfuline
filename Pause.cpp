#include "Pause.h"
#include "SelectScene.h"
#include "GameScene.h"

Pause::Pause()
{
}


Pause::~Pause()
{
}

void Pause::initialize()
{
	m_select_cursor = 0;

	//背景
	m_bg.setTexture(tex.get("black"));
	m_shad.loadFromFile("data/shader/pouse_bg.frag",sf::Shader::Fragment);
	m_shad.setParameter("time", m_clock.getElapsedTime().asSeconds());
	m_state.shader = &m_shad;


	//文字
	TextPos = sf::Vector2f(960,190);

	characterDisplay.setFont("Dosis", "data/font/Dosis-Light.ttf");

	characterDisplay.setCharacter("Sresume", "Dosis", "Resume", TextPos + sf::Vector2f(0, 0), 150);
	characterDisplay.setOrigin( "Sresume", CharacterDisplay::Align::Center);
	characterDisplay.setCharacter("Sreplay", "Dosis", "Replay", TextPos + sf::Vector2f(0, 210), 150);
	characterDisplay.setOrigin("Sreplay", CharacterDisplay::Align::Center);
	characterDisplay.setCharacter("Sback", "Dosis", "Back Menu", TextPos + sf::Vector2f(0, 420), 150);
	characterDisplay.setOrigin("Sback", CharacterDisplay::Align::Center);

	characterDisplay.setCharacter("Lcursor", "Dosis", ">", TextPos + sf::Vector2f(-400, -50), 200);
	characterDisplay.setOrigin("Lcursor", CharacterDisplay::Align::Left);

	sceneMovement.initialize(0);
}

int Pause::update(Scene*& n)
{

	//ブラック
	sceneMovement.update();

	//カーソル
	if (keyManager.push_key(sf::Keyboard::Up)) m_select_cursor -= (m_select_cursor > 0) ? 1 : 0;
	if (keyManager.push_key(sf::Keyboard::Down)) m_select_cursor += (m_select_cursor < 2) ? 1 : 0;

	string key[3] = { "Sresume","Sreplay", "Sback" };
	for (int i = 0; i < 3; i++) characterDisplay.changeColor( key[i], sf::Color(255,255,255,100));
	characterDisplay.changeColor(key[m_select_cursor], sf::Color(255, 255, 255, 255));
	
	characterDisplay.changePosition("Lcursor", sf::Vector2f(sin(m_clock.getElapsedTime().asSeconds())*20 + TextPos.x - 400, characterDisplay.getPosition(key[m_select_cursor]).y - 50));

	//選択
	static bool scene;
	if (keyManager.push_key(sf::Keyboard::Return))
	{
		switch (m_select_cursor)
		{
		case 0: //再開
			return 1;
			break;
		case 1: //リトライ
			sceneMovement.In();
			scene = true;
			break;
		case 2: //セレクト
			sceneMovement.In();
			scene = false;
			break;
		}
	}
	if (sceneMovement.getAlpha() == 255)
	{
		if (scene) n = new GameScene;
		if (!scene) {
			SelectScene s;
			s.setBlackZindex(true);
			n = new SelectScene;
		}
	}

	//bg
	m_shad.setParameter("time", m_clock.getElapsedTime().asSeconds());

	return 3;
}

void Pause::render()
{
	windowManager.getWindow()->draw(m_bg, m_state);
	characterDisplay.render("Sresume");
	characterDisplay.render("Sreplay");
	characterDisplay.render("Sback");
	characterDisplay.render("Lcursor");
	sceneMovement.render();
}
