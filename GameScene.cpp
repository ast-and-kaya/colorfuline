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

	//ƒm[ƒg’Ç‰Á
	for (int i = 0; i < 100; i++) {
		Note note;
		note.setNote(i*0.5, sf::Color::Red);
		//m_note.push_back(note);
	}

	for (int i = 0; i < 100; i++)
	{
		//cout << m_note[i].getSec() << endl;
	}
	
	//cout << m_note.size() << endl;
}


Scene* GameScene::update()
{
	Scene* next = this;

	//ƒV[ƒ“‘JˆÚ
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
}