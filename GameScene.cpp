#include "GameScene.h"

#include "SelectScene.h"
#include "ResultScene.h"

GameScene::GameScene()
{
}


GameScene::~GameScene()
{
}

void GameScene::initialize()
{
	m_game_state = 0;

	cout << musicManager.getItem(config.getNowMusic(config.Num)).music_name << endl;
	cout << config.getNowMusic(config.Num) << endl;

	//ノート追加
	//ファイルの仕様と拡張子を決めておくように
	for (int i = 0; i < 100; i++) {
		m_note.push_back(Note());
		m_note[i].setNote(i*0.5, sf::Color::Red);
		cout << m_note[i].getSec() << endl;
	}

	//音楽ファイル読み込み
	string folder_name = musicManager.getFolderList(config.getNowMusic(config.Num));
	m_music.Load(folder_name,"data/music/" + folder_name + "/music.wav");
	m_music.start();

	pause.initialize();
}


Scene* GameScene::update()
{
	Scene* next = this;

	switch (m_game_state)
	{
	case 0://before
		playBefore();
		break;
	case 1://now
		playNow();
		break;
	case 2://after
		playAfter(next);
		break;
	case 3://stop
		m_game_state = pause.update(next);
		(m_game_state == 1) ? m_music.start() : 0;
		break;
	}

	return next;
}

void GameScene::render()
{
	for (int i = 0; i < m_note.size(); i++)
	{
		m_note[i].render();
	}

	//ポーズ画面
	if(m_game_state == 3) pause.render();
}

void GameScene::playBefore() {
	if (true) m_game_state = 1;
}

void GameScene::playNow() {

	if (keyManager.push_key(sf::Keyboard::Space)) m_game_state = 2;

	//途中停止
	if (keyManager.push_key(sf::Keyboard::Escape)) {
		m_music.pause();
		m_game_state = 3;
	}
}

void GameScene::playAfter(Scene*& n) {
	cout << "after" << endl;

	//リザルト
	if (keyManager.push_key(sf::Keyboard::Return))
	{
		ResultScene result;
		result.setScereData(1234, 5678, 910);
		n = new ResultScene;
	}
}