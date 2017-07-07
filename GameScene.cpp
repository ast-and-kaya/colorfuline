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

	//�m�[�g�ǉ�
	//�t�@�C���̎d�l�Ɗg���q�����߂Ă����悤��
	for (int i = 0; i < 100; i++) {
		m_note.push_back(Note());
		m_note[i].setNote(i*0.5, sf::Color::Red);
		cout << m_note[i].getSec() << endl;
	}

	//���y�t�@�C���ǂݍ���
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

	//�|�[�Y���
	if(m_game_state == 3) pause.render();
}

void GameScene::playBefore() {
	if (true) m_game_state = 1;
}

void GameScene::playNow() {

	if (keyManager.push_key(sf::Keyboard::Space)) m_game_state = 2;

	//�r����~
	if (keyManager.push_key(sf::Keyboard::Escape)) {
		m_music.pause();
		m_game_state = 3;
	}
}

void GameScene::playAfter(Scene*& n) {
	cout << "after" << endl;

	//���U���g
	if (keyManager.push_key(sf::Keyboard::Return))
	{
		ResultScene result;
		result.setScereData(1234, 5678, 910);
		n = new ResultScene;
	}
}