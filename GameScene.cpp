#include "GameScene.h"

GameScene::GameScene()
{
}


GameScene::~GameScene()
{
}

void GameScene::initialize()
{

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
		m_note[i].render();
	}
}

void GameScene::playBefore() {
	cout << "before" << endl;
}

void GameScene::playNow() {
	cout << "now" << endl;

}

void GameScene::playAfter() {
	cout << "after" << endl;

}

void GameScene::playStop() {
	cout << "stop" << endl;

}