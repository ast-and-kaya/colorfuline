#include "GameScene.h"

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
	
	cout << m_note.size() << endl;

	//playStop
	m_select_cursor = 0;
	m_scene_change = false;
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
		playAfter();
		break;
	case 3://stop
		playStop();
		break;
	}

	//シーン遷移
	//セレクト
	if (m_scene_change) next = new SelectScene;
	//リザルト
	if (keyManager.push_key(sf::Keyboard::Return))
	{
		ResultScene result;
		result.setScereData(1234, 5678, 910);
		next = new ResultScene;
	}

	return next;
}

void GameScene::render()
{
	for (int i = 0; i < m_note.size(); i++)
	{
		//m_note[i].render();
	}
}

void GameScene::playBefore() {
	cout << "before" << endl;

	if (keyManager.push_key(sf::Keyboard::Space)) m_game_state = 1;
}

void GameScene::playNow() {
	cout << "now" << endl;

	if (keyManager.push_key(sf::Keyboard::Space)) m_game_state = 2;
}

void GameScene::playAfter() {
	cout << "after" << endl;

}

void GameScene::playStop() {
	cout << "stop" << endl;

	if (keyManager.push_key(sf::Keyboard::Up)) m_select_cursor -= (m_select_cursor > 0) ? 1 : 0;
	if (keyManager.push_key(sf::Keyboard::Down)) m_select_cursor += (m_select_cursor < 2) ? 1 : 0;

	cout << m_select_cursor << endl;

	if (keyManager.push_key(sf::Keyboard::Return))
	{
		switch (m_select_cursor)
		{
			case 0: //再開
				m_game_state = 1;
				break;
			case 1: //リトライ
				initialize();
				break;
			case 2: //セレクト
				m_scene_change = true;
				break;
		}
	}

}