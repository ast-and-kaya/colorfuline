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
	m_music.Load(folder_name, "data/music/" + folder_name + "/music.ogg");

	visualEffect.initialize();

	//�m�[�g�ǉ�
	musicScore.Loading();
	for (int i = 0; i < musicScore.getSize(); i++) {
		m_note.push_back(Note());
		m_note[i].setNote(musicScore.getData(i).time+(0.016*7), musicScore.getData(i).color);
	}

	//���胉�C��
	judgeLine.initialize();

	//�X�R�A���̕���
	//�t�H���g
	characterDisplay.setFont("Dosis", "data/font/Dosis-Light.ttf");
	characterDisplay.setFont("tegaki", "data/font/851tegaki.ttf");
	//����
	characterDisplay.setCharacter("score", "Dosis", to_string((int)m_score), sf::Vector2f(680, 780),160);
	characterDisplay.setOrigin("score", sf::Vector2f(500,0));
	characterDisplay.setCharacter("combo", "Dosis", "x" + to_string((int)m_combo), sf::Vector2f(1600, 780),160);

	keyJudge.initialize();
	pause.initialize();
	supportLine.initialize();
	timeCourse.initialize();
	hitEffect.initialize();
	sceneMovement.initialize();
	sceneMovement.In();

	scoreCalc.setMaxScore(musicScore.getSize(), config.getRawScore(0));
}


Scene* GameScene::update()
{
	Scene* next = this;

	keyJudge.update();
	timer.update();
	sceneMovement.update();
	judgeLine.update();
	timeCourse.update(m_music.getOffset(),m_music.getDuration());

	//cout << m_music.getDuration() << endl;

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

	//�q�b�g���̃G�t�F�N�g
	hitEffect.render();

	//����
	characterDisplay.render("score");
	characterDisplay.render("combo");

	timeCourse.render();

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
	if (m_note.size() != 0 && config.getStartMargin() <= timer.getTime()) {
		m_music.start();//�Đ����͖���
	}

	visualEffect.updata(m_music.getOffset());

	int judge = m_note[0].judge(timer.getTime() - config.getStartMargin(), keyJudge.getKeyColor());

	//��������
	if (judge != 0)
	{
		//cout << judge << endl;
		m_combo++;
		hitEffect.action();

		switch (judge)
		{
		case 1://great
			m_score += scoreCalc.add( m_combo, config.getRawScore(0));
			m_great++;
			break;
		case 2://good
			m_score += scoreCalc.add(m_combo, config.getRawScore(1));
			break;
		case 3://bad
			m_score += scoreCalc.add(m_combo, config.getRawScore(2));
			break;
		}
		if (m_note.begin() != m_note.end()) {
			m_note.erase(m_note.begin());
		}
		
	}
	hitEffect.update();

	//��ʊO(�~�X)����
	if (!m_note.empty())
	{
		if (m_note[0].rangeOut(timer.getTime() - config.getStartMargin()))
		{
			//�R���{���f�ƍX�V
			m_maxcombo = (m_maxcombo < m_combo) ? m_combo : m_maxcombo;
			m_combo = 0;
			m_note.erase(m_note.begin());
		}
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
	string s = to_string(m_score / scoreCalc.getMaxScore() * 100.f);
	for (int i = 0; i < 4; i++) s.pop_back();
	characterDisplay.changeString("score", s);
	characterDisplay.changeString("combo", "x" + to_string((int)m_combo));

	//�A�t�^�[�ړ�
	//if (keyManager.push_key(sf::Keyboard::Return)) {
	if (m_note.size() == 0 && !m_music.getState()){
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
		result.setScereData(m_score / scoreCalc.getMaxScore() * 100.f, m_maxcombo, m_great, musicScore.getSize());
		n = new ResultScene;
	}
}