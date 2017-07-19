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

	m_score = 0;
	m_perfect = 0;
	m_maxcombo = 0;

	m_combo = 0;

	//cout << musicManager.getItem(config.getNowMusic(config.Num)).music_name << endl;
	//cout << config.getNowMusic(config.Num) << endl;

	//�m�[�g�ǉ�
	//�t�@�C���̎d�l�Ɗg���q�����߂Ă���
	sf::Color c[3] = {sf::Color::Red,sf::Color::Green,sf::Color::Blue};
	for (int i = 0; i < 300; i++) {
		m_note.push_back(Note());
		m_note[i].setNote(i*(60.f/162.f), c[i%3]);
		//cout << m_note[i].getSec() << endl;
	}

	//���胉�C��
	m_judge_line.setTexture(tex.get("game_judge_line"));
	m_judge_line.setPosition(0,900);

	//�X�R�A���̕���
	//�t�H���g
	characterDisplay.setFont("Dosis", "data/font/Dosis-Light.ttf");
	characterDisplay.setFont("tegaki", "data/font/851tegaki.ttf");
	//����
	characterDisplay.setCharacter("score", "Dosis", to_string(m_score), sf::Vector2f(0, 0));

	//���y�t�@�C���ǂݍ���
	string folder_name = musicManager.getFolderList(config.getNowMusic(config.Num));
	m_music.Load(folder_name,"data/music/" + folder_name + "/music.wav");

	pause.initialize();
	supportLine.initialize();
}


Scene* GameScene::update()
{
	Scene* next = this;

	keyJudge.update();

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
	supportLine.render();

	//���胉�C��
	windowManager.getWindow()->draw(m_judge_line);

	//����
	characterDisplay.render();

	//�m�[�g
	for (auto& it: m_note)
	{
		it.render();
	}

	//�|�[�Y���
	if(m_game_state == 3) pause.render();
}

void GameScene::playBefore() {
	m_game_state = 1;
}

void GameScene::playNow() {

	if (m_start_margin <= m_clock.getElapsedTime().asSeconds()) {
		m_music.start();//�Đ����͖���
	}

	int judge = m_note[0].judge(m_clock.getElapsedTime().asSeconds() - m_start_margin, keyJudge.getKeyColor());
	

	//��������
	if (judge != 0)
	{
		cout << judge << endl;
		
		m_combo++;

		switch (judge)
		{
		case 1://perfect
			break;
		case 2://great
			break;
		case 3://good
			break;
		}
		
		m_note.erase(m_note.begin());
	}

	//��ʊO(�~�X)����
	if (m_note[0].rangeOut(m_clock.getElapsedTime().asSeconds() - m_start_margin))
	{
		//�R���{���f�ƍX�V
		m_maxcombo = (m_maxcombo < m_combo) ? m_combo : m_maxcombo;
		m_combo = 0;
		m_note.erase(m_note.begin());
	}

	for (auto& it : m_note)
	{
		it.update(m_clock.getElapsedTime().asSeconds() - m_start_margin);
	}

	supportLine.update();

	//���Y��
	//float f = (m_clock.getElapsedTime().asSeconds() - m_start_margin) - m_music.getOffset();
	//cout << f << endl;
	

	//�A�t�^�[�ړ�
	if (m_note.size() == 0) m_game_state = 2;

	//�r����~
	if (keyManager.push_key(sf::Keyboard::Escape)) {
		m_music.pause();
		m_game_state = 3;
	}
}

void GameScene::playAfter(Scene*& n) {
	m_maxcombo = (m_maxcombo < m_combo) ? m_combo : m_maxcombo;

	//���U���g
	if (keyManager.push_key(sf::Keyboard::Return))
	{
		ResultScene result;
		result.setScereData(m_score, m_maxcombo, m_perfect);
		n = new ResultScene;
	}
}