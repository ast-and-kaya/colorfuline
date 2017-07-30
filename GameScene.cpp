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

	m_score = 0;
	m_perfect = 0;
	m_maxcombo = 0;

	m_note_number = 0;

	m_combo = 0;

	//���y�t�@�C���ǂݍ���
	string folder_name = musicManager.getFolderList(config.getNowMusic(config.Num));
	m_music.Load(folder_name, "data/music/" + folder_name + "/music.wav");

	//cout << config.getNowMusic(config.Num) << endl;

	//�m�[�g�ǉ�
	//�t�@�C���̎d�l�Ɗg���q�����߂Ă���
	sf::Color c[3] = {sf::Color::Red,sf::Color::Green,sf::Color::Blue};
	for (int i = 0; i < 300; i++) {
		m_note.push_back(Note());
		m_note[i].setNote(i*(60.f/162.f), c[i%3]);

		m_note_number++;
	}

	//���胉�C��
	m_judge_line.setTexture(tex.get("game_judge_line"));
	m_judge_line.setPosition(0, config.getLaneDistance());
	m_judge_line.setOrigin(0, tex.get("game_judge_line").getSize().y / 2.f);

	//�X�R�A���̕���
	//�t�H���g
	characterDisplay.setFont("Dosis", "data/font/Dosis-Light.ttf");
	characterDisplay.setFont("tegaki", "data/font/851tegaki.ttf");
	//����
	characterDisplay.setCharacter("score", "Dosis", to_string((int)m_score), sf::Vector2f(100, 780),160);
	characterDisplay.setCharacter("combo", "Dosis", "x" + to_string((int)m_combo), sf::Vector2f(1600, 780),160);
	characterDisplay.setCharacter("title", "tegaki", musicManager.getItem(config.getNowMusic(config.Num)).music_name, sf::Vector2f(50, 0),75);
	characterDisplay.setCharacter("artist", "tegaki", musicManager.getItem(config.getNowMusic(config.Num)).artist, sf::Vector2f(50, 100),60);

	pause.initialize();
	supportLine.initialize();
	timer.initialize();
	sceneMovement.initialize();
	sceneMovement.Out();
}


Scene* GameScene::update()
{
	Scene* next = this;

	keyJudge.update();
	timer.update();
	sceneMovement.update();

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
		if (m_game_state == 1) {
			m_music.start();
			timer.start();
		}
		break;
	}

	return next;
}

void GameScene::render()
{
	supportLine.render();

	//����
	characterDisplay.render("score");
	characterDisplay.render("combo");
	characterDisplay.render("title");
	characterDisplay.render("artist");

	//���胉�C��
	windowManager.getWindow()->draw(m_judge_line);

	//�m�[�g
	for (auto& it: m_note)
	{
		it.render();
	}

	sceneMovement.render();

	//�|�[�Y���
	if(m_game_state == 3) pause.render();

}

void GameScene::playBefore() {
	m_game_state = 1;
}

void GameScene::playNow() {

	//�ȃX�^�[�g
	if (config.getStartMargin() <= timer.getTime()) {
		m_music.start();//�Đ����͖���
	}

	int judge = m_note[0].judge(timer.getTime() - config.getStartMargin(), keyJudge.getKeyColor());

	//��������
	if (judge != 0)
	{
		//cout << judge << endl;
		m_combo++;

		switch (judge)
		{
		case 1://perfect
			m_score += 100;
			m_perfect++;
			break;
		case 2://great
			m_score += 10;
			break;
		case 3://good
			m_score += 1;
			break;
		}
		m_note.erase(m_note.begin());
	}

	//��ʊO(�~�X)����
	if (m_note[0].rangeOut(timer.getTime() - config.getStartMargin()))
	{
		//�R���{���f�ƍX�V
		m_maxcombo = (m_maxcombo < m_combo) ? m_combo : m_maxcombo;
		m_combo = 0;
		m_note.erase(m_note.begin());
	}

	for (auto& it : m_note)
	{
		it.update(timer.getTime() - config.getStartMargin());
	}

	supportLine.update();

	//���Y��
	//float f = (timer.getTime() - m_start_margin) - m_music.getOffset();
	//cout << f << endl;

	//�X�R�A�\���X�V
	characterDisplay.changeString("score", to_string((int)m_score));
	characterDisplay.changeString("combo", "x" + to_string((int)m_combo));

	//�A�t�^�[�ړ�
	if (m_note.size() == 0 || keyManager.push_key(sf::Keyboard::Return)){
		m_music.stop();
		sceneMovement.In();
		m_game_state = 2;//�b��
	}

	//�r����~
	if (keyManager.push_key(sf::Keyboard::Escape)) {
		timer.pouse();
		m_music.pause();
		m_game_state = 3;
	}
}

void GameScene::playAfter(Scene*& n) {

	//���U���g
	if (sceneMovement.getAlpha() == 255)
	{
		m_maxcombo = (m_maxcombo < m_combo) ? m_combo : m_maxcombo;
		ResultScene result;
		result.setScereData(m_score, m_maxcombo, m_perfect, m_note_number);
		n = new ResultScene;
	}
}