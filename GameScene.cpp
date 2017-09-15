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
	m_great = 0;
	m_maxcombo = 0;

	m_combo = 0;

	m_black_zindex = false;

	//���y�t�@�C���ǂݍ���
	string folder_name = musicManager.getFolderList(config.getNowMusic(config.Num));
	m_music.Load(folder_name, "data/music/" + folder_name + "/music.wav");

	visualEffect.initialize("data/music/" + folder_name + "/music.wav");

	//�m�[�g�ǉ�
	musicScore.Loading();
	for (int i = 0; i < 1000; i++) {
		m_note.push_back(Note());
		m_note[i].setNote(musicScore.getData(i).time, musicScore.getData(i).color);
	}

	//���胉�C��
	judgeLine.initialize();

	//�X�R�A���̕���
	//�t�H���g
	characterDisplay.setFont("Dosis", "data/font/Dosis-Light.ttf");
	characterDisplay.setFont("tegaki", "data/font/851tegaki.ttf");
	//����
	characterDisplay.setCharacter("score", "Dosis", to_string((int)m_score), sf::Vector2f(100, 780),160);
	characterDisplay.setCharacter("combo", "Dosis", "x" + to_string((int)m_combo), sf::Vector2f(1600, 780),160);

	keyJudge.initialize();
	pause.initialize();
	supportLine.initialize();
	sceneMovement.initialize();
	sceneMovement.In();
}


Scene* GameScene::update()
{
	Scene* next = this;

	keyJudge.update();
	timer.update();
	sceneMovement.update();
	judgeLine.update();
	visualEffect.updata(m_music.getOffset());

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
			if (config.getStartMargin() <= timer.getTime()) m_music.start();
			timer.start();
		}
		break;
	}

	return next;
}

void GameScene::render()
{
	//�w�i
	visualEffect.render();

	//supportLine.render();

	//����
	characterDisplay.render("score");
	characterDisplay.render("combo");

	if (!m_black_zindex)sceneMovement.render();

	//���胉�C��
	judgeLine.render();

	//�m�[�g
	for (auto& it: m_note)
	{
		it.render();
	}

	if (m_black_zindex)sceneMovement.render();

	//�|�[�Y���
	if(m_game_state == 3) pause.render();

	musicGuide.render();
}

void GameScene::playBefore() {
	if (judgeLine.pre())
	{
		sceneMovement.Out();
		timer.initialize();
		m_game_state = 1;
	}
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
		case 1://great
			m_score += 1;
			m_great++;
			break;
		case 2://good
			m_score += 0.1;
			break;
		case 3://bad
			m_score += 0.01;
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
	float f = (timer.getTime() - config.getStartMargin()) - m_music.getOffset();
	//cout << f << endl;

	//�X�R�A�\���X�V
	characterDisplay.changeString("score", to_string((int)m_score));
	characterDisplay.changeString("combo", "x" + to_string((int)m_combo));

	//�A�t�^�[�ړ�
	if (m_note.size() == 0 || keyManager.push_key(sf::Keyboard::Return)){
		m_music.stop();
		sceneMovement.In();
		m_black_zindex = true;
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
		result.setScereData(m_score, m_maxcombo, m_great, musicScore.getSize());
		n = new ResultScene;
	}
}