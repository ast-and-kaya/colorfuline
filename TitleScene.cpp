#include "TitleScene.h"



TitleScene::TitleScene()
{
}


TitleScene::~TitleScene()
{
}

void TitleScene::initialize()
{
	//背景
	m_bg.setTexture(tex.get("black"));
	m_bg_shad.loadFromFile("data/shader/title_bg.frag",sf::Shader::Fragment);
	m_bg_shad.setParameter("resolution", sf::Vector2f(config.m_window_size.x, config.m_window_size.y));
	m_bg_state.shader = &m_bg_shad;

	//ロゴ
	m_logo.setTexture(tex.get("title_logo"));
	m_logo.setOrigin(m_logo.getGlobalBounds().width/2, 0);
	m_logo.setPosition(sf::Vector2f(960, 100));

	//ロゴ２
	m_logo_blur.setTexture(tex.get("title_logo_blur"));
	m_logo_blur.setOrigin(m_logo_blur.getGlobalBounds().width/2, 0);
	m_logo_blur.setPosition(sf::Vector2f(960, 100));
	m_logo_blur.setColor(sf::Color(255, 255, 255, 0));

	//文字
	font.loadFromFile("data/font/Dosis-Light.ttf");
	//start
	m_txt_start.setString("START");
	m_txt_start.setFont(font);
	m_txt_start.setCharacterSize(120);
	m_txt_start.setOrigin(m_txt_start.getGlobalBounds().width/2,0);
	m_txt_start.setPosition(1920 / 7 * 2.0,800);
	//exit
	m_txt_exit.setString("EXIT");
	m_txt_exit.setFont(font);
	m_txt_exit.setCharacterSize(120);
	m_txt_exit.setOrigin(m_txt_exit.getGlobalBounds().width / 2, 0);
	m_txt_exit.setPosition(1920 / 7 * 5.0, 800);

	//セレクトバー
	m_select.setTexture(tex.get("title_select"));
	m_select.setOrigin(350,0);
	m_select_tf = true;
	m_select_posx[0] = 1920 / 7 * 5.0;
	m_select_posx[1] = 1920 / 7 * 2.0;
	m_select.setPosition(m_select_posx[m_select_tf],920-2);

	//シーン移動
	sceneMovement.initialize(0);
}

Scene* TitleScene::update()
{
	Scene* next = this;

	m_bg_shad.loadFromFile("data/shader/title_bg.frag", sf::Shader::Fragment);
	m_bg_shad.setParameter("resolution", sf::Vector2f(config.m_window_size.x, config.m_window_size.y));

	m_bg_shad.setParameter("time", m_clock.getElapsedTime().asSeconds());

	//ロゴぼんやり加減
	float al = sin(m_clock.getElapsedTime().asSeconds() * 2) + 1;
	m_logo_blur.setColor(sf::Color(255, 255, 255, al / 2 * 255));

	//セレクトバー
	if (keyManager.push_key(sf::Keyboard::Right) || keyManager.push_key(sf::Keyboard::Left)) {
		m_select_tf = !m_select_tf;
		m_select.setScale(0, 1);
	}
	m_select.setPosition(m_select_posx[m_select_tf], 920-2);//位置変更
	if (m_select.getScale().x < 1) m_select.setScale(m_select.getScale().x+0.15,1);//セレクトバースケール調整


	//Enter
	if (keyManager.push_key(sf::Keyboard::Return))
	{
		if (m_select_tf) {//start
			sceneMovement.In();
		}
		else {//exit
			windowManager.getWindow()->close();
		}
	}
	
	sceneMovement.update();

	//タイトルフェード後にシーン移行
	if (sceneMovement.getAlpha() == 255)
	{
		SelectScene s;
		s.setBlackZindex(false);
		next = new SelectScene;
	}

	return next;
}

void TitleScene::render()
{
	windowManager.getWindow()->draw(m_bg, m_bg_state);
	windowManager.getWindow()->draw(m_logo);
	windowManager.getWindow()->draw(m_logo_blur);
	windowManager.getWindow()->draw(m_txt_start);
	windowManager.getWindow()->draw(m_txt_exit);
	windowManager.getWindow()->draw(m_select);
	sceneMovement.render();
}