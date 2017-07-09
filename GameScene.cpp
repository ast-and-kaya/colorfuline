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
	m_start_margin = 3.0f;

	cout << musicManager.getItem(config.getNowMusic(config.Num)).music_name << endl;
	cout << config.getNowMusic(config.Num) << endl;

	//�m�[�g�ǉ�
	//�t�@�C���̎d�l�Ɗg���q�����߂Ă����悤��
	for (int i = 0; i < 100; i++) {
		m_note.push_back(Note());
		m_note[i].setNote(i*0.5, sf::Color::Red);
		cout << m_note[i].getSec() << endl;
	}

	//���胉�C��
	m_judge_line.setTexture(tex.get("game_judge_line"));
	m_judge_line.setPosition(0,900);

	//���y�t�@�C���ǂݍ���
	string folder_name = musicManager.getFolderList(config.getNowMusic(config.Num));
	m_music.Load(folder_name,"data/music/" + folder_name + "/music.wav");

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
	//���胉�C��
	windowManager.getWindow()->draw(m_judge_line);

	//�m�[�g
	for (auto& it: m_note)
	{
		it.render();
	}

	//�|�[�Y���
	if(m_game_state == 3) pause.render();
}

void GameScene::playBefore() {
	for (auto& it : m_note)
	{
		it.update(m_clock.getElapsedTime().asSeconds() - m_start_margin);
	}
	if (m_start_margin <= m_clock.getElapsedTime().asSeconds()) {
		m_game_state = 1;
		m_music.start();
	}
}

void GameScene::playNow() {

	if (keyManager.push_key(sf::Keyboard::Space)) m_game_state = 2;

	for (auto& it : m_note)
	{
		it.update(m_clock.getElapsedTime().asSeconds() - m_start_margin);
	}

	float f = (m_clock.getElapsedTime().asSeconds() - m_start_margin) - m_music.getOffset();
	cout << f << endl;
	

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