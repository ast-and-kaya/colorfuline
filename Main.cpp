#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

#include "Scene.h"

#include "TestRoom.h"
#include "TitleScene.h"
#include "LoadingScene.h"

using namespace std;

//使用ライブラリ： SFML-2.3.2 / picojson
int main()
{
	//コンフィグ
	ConfigManager config;
	config.DataLoading();
	config.initialize();

	//楽曲データ
	MusicManager musicManager;
	musicManager.DataLoding();

	//ハイスコアデータ
	ScoreManager scoreManager;
	scoreManager.DataLoad();

	//ゲーム内テクスチャ
	TextureManager textureManager;
	textureManager.Loading();

	//SFMLでウィンドウの作成と設定
	sf::RenderWindow m_window(sf::VideoMode(config.m_window_size.x, config.m_window_size.y), "colorfuline ver.2.0", sf::Style::Close);
	m_window.setFramerateLimit(60);
	m_window.setView(sf::View(sf::FloatRect(0,0,1920,1080)));

	//ウィンドウをstaticで保持　その他ウィンドウの機能用
	WindowManager windowManager;
	windowManager.setWindow(&m_window);
	windowManager.setWindowActive(true);

	//シーンの切り替え用クラス
	Scene* m_scene;
	m_scene = new TitleScene;
	m_scene->initialize();

	//メインループ
	while (m_window.isOpen())
	{
		sf::Clock c;//処理時間のデバッグ用

		sf::Event event;//sfmlイベント

		while (m_window.pollEvent(event))//ウィンドウイベント
		{
			if (event.type == sf::Event::Closed) m_window.close();//閉じる

			//ウィンドウのアクティブ検知
			if (event.type == sf::Event::LostFocus) windowManager.setWindowActive(false);
			if (event.type == sf::Event::GainedFocus) windowManager.setWindowActive(true);

		}

		//シーンのupdateと切り替わり
		Scene* next_scene = m_scene->update();
		if (m_scene != next_scene)
		{
			m_scene = next_scene;
			m_scene->initialize();
		}

		m_window.clear();//消し

		m_scene->render();//シーンのレンダリング

		m_window.display();//描き


	}

	return 0;
}