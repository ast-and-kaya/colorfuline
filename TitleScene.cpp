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
	m_bg.setTexture(tex.get("title_bg"));

	//3色リング
	m_ring.setTexture(tex.get("title_ring"));
	m_shad_ring.loadFromFile("data/shader/title_ring.frag",sf::Shader::Fragment);
	m_shad_ring.setParameter("tex", tex.get("title_ring"));
	m_shad_ring.setParameter("tex2", tex.get("title_ring_sub"));
	m_rs_ring.shader = &m_shad_ring;

	m_ring_alpha = 1;

	//ロゴ
	m_logo.setTexture(tex.get("title_logo"));
	m_logo.setPosition(sf::Vector2f(850, 150));

	//ロゴ２
	m_logo_blur.setTexture(tex.get("title_logo_blur"));
	m_logo_blur.setPosition(sf::Vector2f(850, 150));
	m_logo_blur.setColor(sf::Color(255, 255, 255, 0));

	//最初にフェードアウトする黒
	m_black.setTexture(tex.get("black"));
	m_black_alpha = 255;
	m_black.setColor(sf::Color(0, 0, 0, m_black_alpha));

	//文字
	font.loadFromFile("data/font/Dosis-Light.ttf");
	//start
	m_txt_start.setString("START");
	m_txt_start.setFont(font);
	m_txt_start.setCharacterSize(120);
	m_txt_start.setPosition(950,700);
	//exit
	m_txt_exit.setString("EXIT");
	m_txt_exit.setFont(font);
	m_txt_exit.setCharacterSize(120);
	m_txt_exit.setPosition(1500, 700);

	//セレクトバー
	m_select.setTexture(tex.get("title_select"));
	m_select.setOrigin(350,0);
	m_select_tf = true;
	m_select_posx[0] = 1600;
	m_select_posx[1] = 1090;
	m_select.setPosition(m_select_posx[m_select_tf],820);

	//シーン移動
	sceneMovement.initialize(0);
}

Scene* TitleScene::update()
{
	Scene* next = this;

	if (m_ring_alpha >= 0) m_ring_alpha -= 0.015;
	m_shad_ring.setParameter("r", m_ring_alpha);

	if (m_black_alpha != 0 && m_ring_alpha <= 0)
	{
		//ブラック透過
		m_black_alpha -= 1.5;
	}
	m_black.setColor(sf::Color(0, 0, 0, m_black_alpha));

	//ロゴぼんやり加減
	float al = sin(blur_clock.getElapsedTime().asSeconds() * 2) + 1;
	m_logo_blur.setColor(sf::Color(255, 255, 255, al / 2 * 255));

	//セレクトバー
	if (keyManager.push_key(sf::Keyboard::Right) || keyManager.push_key(sf::Keyboard::Left)) {
		m_select_tf = !m_select_tf;
		m_select.setScale(0, 1);
	}
	m_select.setPosition(m_select_posx[m_select_tf], 820);//位置変更
	if (m_select.getScale().x < 1) m_select.setScale(m_select.getScale().x+0.15,1);//セレクトバースケール調整


	//Enter
	if (keyManager.push_key(sf::Keyboard::Return))
	{
		m_black_alpha = 0;//全面黒を透明に
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
		next = new SelectScene;
	}

	return next;
}

void TitleScene::render()
{
	windowManager.getWindow()->draw(m_bg);
	windowManager.getWindow()->draw(m_logo);
	windowManager.getWindow()->draw(m_logo_blur);
	windowManager.getWindow()->draw(m_txt_start);
	windowManager.getWindow()->draw(m_txt_exit);
	windowManager.getWindow()->draw(m_select);
	windowManager.getWindow()->draw(m_black);
	windowManager.getWindow()->draw(m_ring, m_rs_ring);
	sceneMovement.render();
}